#include "vicon_unlabeled_marker_receiver/communicator.hpp"

using namespace ViconDataStreamSDK::CPP;

namespace ViconReceiver {
namespace UnlabeledMarker {


Communicator::Communicator() : Node("vicon_unlabeled_markers") {
  // get parameters
  this->declare_parameter<std::string>("hostname", "127.0.0.1");
  this->declare_parameter<int>("buffer_size", 200);
  this->declare_parameter<std::string>("namespace", "vicon_unlabeled_markers");
  this->get_parameter("hostname", hostname);
  this->get_parameter("buffer_size", buffer_size);
  this->get_parameter("namespace", ns_name);
}

bool Communicator::connect() {
  // connect to server
  std::string msg = "Connecting to " + hostname + " ...";
  std::cout << msg << std::endl;
  std::size_t counter = 0;
  while (!vicon_client.IsConnected().Connected) {
    bool ok = (vicon_client.Connect(hostname).Result == Result::Success);
    if (!ok) {
      counter++;
      msg = "Connect failed, reconnecting (" + std::to_string(counter) + ")...";
      std::cout << msg << std::endl;
      sleep(1);
    }
  }
  msg = "Connection successfully established with " + hostname;
  std::cout << msg << std::endl;

  // perform further initialization
  // vicon_client.EnableSegmentData();
  // vicon_client.EnableMarkerData();
  vicon_client.EnableUnlabeledMarkerData();
  // vicon_client.EnableMarkerRayData();
  vicon_client.EnableDeviceData();
  vicon_client.EnableDebugData();

  vicon_client.SetStreamMode(StreamMode::ClientPull);
  vicon_client.SetBufferSize(buffer_size);

  msg = "Initialization complete";
  std::cout << msg << std::endl;

  return true;
}

bool Communicator::fetch_markers(MarkersStruct& markers) {
  vicon_client.GetFrame();
  std::size_t marker_count_now = vicon_client.GetUnlabeledMarkerCount().MarkerCount;
  if (marker_count_now != marker_count){
      std::cout << "Warning: Marker count mismatch: " << marker_count_now << std::endl;
    sleep(0.1);
    return false;
  }

  Output_GetUnlabeledMarkerGlobalTranslation unlabeled_marker_translation;
  for (std::size_t i = 0; i < marker_count; ++i) {
    unlabeled_marker_translation = vicon_client.GetUnlabeledMarkerGlobalTranslation(i);
    markers.x[i] = unlabeled_marker_translation.Translation[0];
    markers.y[i] = unlabeled_marker_translation.Translation[1];
    markers.z[i] = unlabeled_marker_translation.Translation[2];
    markers.indices[i] = i;
  }
  return true;
}

bool Communicator::disconnect() {
  if (!vicon_client.IsConnected().Connected)
    return true;
  sleep(1);
  vicon_client.DisableSegmentData();
  vicon_client.DisableMarkerData();
  vicon_client.DisableUnlabeledMarkerData();
  vicon_client.DisableDeviceData();
  vicon_client.DisableCentroidData();
  std::string msg = "Disconnecting from " + hostname + "...";
  std::cout << msg << std::endl;
  vicon_client.Disconnect();
  msg = "Successfully disconnected";
  std::cout << msg << std::endl;
  if (!vicon_client.IsConnected().Connected)
    return true;
  return false;
}

template <typename T>
std::size_t Communicator::find_majority_element(const std::deque<T>& nums) {
  std::size_t majority = nums.front();
  std::size_t count = 1;

  for (std::size_t i = 1; i < nums.size(); ++i) {
    if (count == 0) {
      majority = nums[i];
      count = 1;
    } else if (majority == nums[i]) {
      count++;
    } else {
      count--;
    }
  }

  // Verify if the found majority element is actually the majority
  count = 0;
  for (T num : nums) {
    if (num == majority) {
      count++;
    }
  }

  // If no majority element found, return the most recently stored element
  if (count <= nums.size() / 2) {
    return nums.back();
  }

  return majority;
}

// Calculate the time difference between two timecodes
inline double Communicator::frame_delta_time(double& current_frame_time){
    return current_frame_time - Communicator::previous_frame_time;
}

inline double Communicator::calculate_distance(const std::vector<double>& a, const std::vector<double>& b) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2));
}

std::vector<std::size_t> Communicator::hungarian_algorithm(const std::vector<std::vector<double>>& costMatrix) {
    std::size_t n = costMatrix.size();
    std::size_t m = costMatrix[0].size();
    std::cout<<"HA " << n << " " << m << std::endl;

    std::vector<std::size_t> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    std::vector<std::size_t> minv(m + 1, std::numeric_limits<std::size_t>::max());
    std::vector<bool> used(m + 1, false);

    std::size_t i0;
    std::size_t j0, j1;
    std::size_t delta, cur;
    for (std::size_t i = 1; i <= n; ++i) {
        // initialize minv and used
        std::fill(minv.begin(), minv.end(), std::numeric_limits<std::size_t>::max());
        std::fill(used.begin(), used.end(), false);

        j0 = 0;
        p[0] = i;
        do {
            used[j0] = true;
            i0 = p[j0];

            delta = std::numeric_limits<std::size_t>::max();
            for (std::size_t j = 1; j <= m; ++j) {
                if (!used[j]) {
                    cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (std::size_t j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    std::vector<std::size_t> result(n);
    for (std::size_t j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            result[p[j] - 1] = j - 1;
        }
    }
    return result;
}

std::pair<std::vector<std::pair<std::size_t, std::size_t>>, double> Communicator::findOptimalAssignment(
    const MarkersStruct& current_marker,
    const MarkersStruct& prev_marker) {

    std::size_t n = current_marker.indices.size();
    std::size_t m = prev_marker.indices.size();
    std::vector<std::vector<double>> costMatrix(n, std::vector<double>(m));
    std::vector<double> current_marker_pos(3), prev_marker_pos(3);

    // Calculate the cost matrix
    for (std::size_t i = 0; i < n; ++i) {
        current_marker_pos = {current_marker.x[i], current_marker.y[i], current_marker.z[i]};
        for (std::size_t j = 0; j < m; ++j) {
            prev_marker_pos = {prev_marker.x[j], prev_marker.y[j], prev_marker.z[j]};
            costMatrix[i][j] = calculate_distance(current_marker_pos, prev_marker_pos);
        }
    }

    // // Apply Hungarian Algorithm to find the optimal assignment
    std::vector<std::size_t> assignment = hungarian_algorithm(costMatrix);

    // Create the result as pairs of (current_marker index, prev_marker index)
    std::vector<std::pair<std::size_t, std::size_t>> result;
    double totalCost = 0;
    for (std::size_t i = 0; i < n; ++i) {
        result.emplace_back(i, assignment[i]);
        totalCost += costMatrix[i][assignment[i]]; // Sum the cost for each assignment
    }

    return std::make_pair(result, totalCost);
}


void Communicator::get_frame() {
  if (!vicon_client.IsConnected().Connected) {
      std::cout << "Not connected to server" << std::endl;
    // wait 1 sec to try next
    sleep(1);
    return;
  }
  if (!flag_initialized){
    // std::vector<std::size_t> marker_count_total;
    Utility::FixedQueue<std::size_t, 120> marker_count_total;

    // Get first frame information
    std::size_t frame_number;
    for (std::size_t i = 0; i < 120; i++){
      vicon_client.GetFrame();
      frame_number = vicon_client.GetFrameNumber().FrameNumber;
      marker_count = vicon_client.GetUnlabeledMarkerCount().MarkerCount;
      marker_count_total.emplace_back(marker_count);
    }
    marker_count = find_majority_element(marker_count_total);
    if (marker_count == 0){
      std::cout << "Warning: Unlabeled Markers not found" << '\n';
      return;
    }

    previous_markers = MarkersStruct(marker_count, frame_number);
    while (!Communicator::fetch_markers(previous_markers)){}
    auto now = std::chrono::system_clock::now();
    Communicator::previous_frame_time = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    std::cout << "Initial marker counts: " << marker_count << std::endl;
    flag_initialized = true;
  }

  vicon_client.GetFrame();
  Output_GetFrameNumber frame_number = vicon_client.GetFrameNumber();
  std::cout << "If success get frame, return 2:"<<frame_number.Result << ' framenumber:' <<  frame_number.FrameNumber << std::endl;
  // std::cout << "Current frame time: " << current_frame_time << " ms" << std::endl;

  // std::size_t marker_count_now = vicon_client.GetUnlabeledMarkerCount().MarkerCount; //data.positions[1].size(),we have 6 unlabeled markers;
  // Output_GetUnlabeledMarkerCount unlabeled_marker_count = vicon_client.GetUnlabeledMarkerCount();
  // std::size_t marker_count = unlabeled_marker_count.MarkerCount;
  // if (unlabeled_marker_count.Result != Result::Success or unlabeled_marker_count.MarkerCount == 0){
  //   std::cout << "Warning: Unlabeled Markers not found" << unlabeled_marker_count.Result << '\n';
  //   std::cout << "  " << unlabeled_marker_count.MarkerCount << std::endl;
  //   return;
  // }

  MarkersStruct current_markers(marker_count, frame_number.FrameNumber);
  while (!Communicator::fetch_markers(current_markers)){ }
  auto now = std::chrono::system_clock::now();
  double current_frame_time = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

  // Compute Velocity
  double delta_time = Communicator::frame_delta_time(current_frame_time) / 1000.0; // convert to seconds
  std::cout << "Delta time: " << delta_time << " ms" << std::endl;

  auto [assignment, totalCost] = findOptimalAssignment(current_markers, Communicator::previous_markers);
  std::cout << "Total cost: " << totalCost << std::endl;
  for (const auto& [current_idx, prev_idx] : assignment) {
    current_markers.vx[current_idx] = (current_markers.x[current_idx] - Communicator::previous_markers.x[prev_idx])/delta_time;
    current_markers.vy[current_idx] = (current_markers.y[current_idx] - Communicator::previous_markers.y[prev_idx])/delta_time;
    current_markers.vz[current_idx] = (current_markers.z[current_idx] - Communicator::previous_markers.z[prev_idx])/delta_time;
  }

  // Pass step
  Communicator::previous_markers = current_markers;
  Communicator::previous_frame_time = current_frame_time;

  // send position to publisher
  std::map<std::string, Publisher>::iterator pub_it;
  boost::mutex::scoped_try_lock lock(mutex);
  const std::string subject_name = "unlabeled_markers";
  const std::string segment_name = "positions_velocity";

  if (lock.owns_lock()) {
    // get publisher
    pub_it = pub_map.find(subject_name + "/" + segment_name);
    if (pub_it != pub_map.end()) {
      Publisher &pub = pub_it->second;

      if (pub.is_ready) {
        pub.publish(current_markers);
      }
    } else {
      // create publisher if not already available
      lock.unlock();
      create_publisher(subject_name, segment_name);
    }
  }
}

void Communicator::create_publisher(const std::string subject_name,
                                    const std::string segment_name) {
  boost::thread(&Communicator::create_publisher_thread, this, subject_name,
                segment_name);
}

void Communicator::create_publisher_thread(const std::string subject_name,
                                           const std::string segment_name) {
  std::string topic_name = ns_name + "/" + subject_name + "/" + segment_name;
  std::string key = subject_name + "/" + segment_name;

  std::string msg = "Creating publisher for segment " + segment_name +
               " from subject " + subject_name;
  std::cout << msg << std::endl;

  // create publisher
  boost::mutex::scoped_lock lock(mutex);
  pub_map.insert(std::map<std::string, Publisher>::value_type(
      key, Publisher(topic_name, this)));

  // we don't need the lock anymore, since rest is protected by is_ready
  lock.unlock();
}

} // namespace UnlabeledMarker
} // namespace ViconReceiver

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ViconReceiver::UnlabeledMarker::Communicator>();
  node->connect();

  while (rclcpp::ok()) {
    node->get_frame();
  }

  node->disconnect();
  rclcpp::shutdown();
  return 0;
}
