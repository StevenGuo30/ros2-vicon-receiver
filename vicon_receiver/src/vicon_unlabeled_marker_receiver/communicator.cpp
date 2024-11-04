#include "vicon_unlabeled_marker_receiver/communicator.hpp"

using namespace ViconDataStreamSDK::CPP;

namespace ViconReceiver {
namespace UnlabeledMarker {

bool is_first_frame = true;
std::vector<std::size_t> marker_count_total;

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
  string msg = "Connecting to " + hostname + " ...";
  cout << msg << endl;
  int counter = 0;
  while (!vicon_client.IsConnected().Connected) {
    bool ok = (vicon_client.Connect(hostname).Result == Result::Success);
    if (!ok) {
      counter++;
      msg = "Connect failed, reconnecting (" + std::to_string(counter) + ")...";
      cout << msg << endl;
      sleep(1);
    }
  }
  msg = "Connection successfully established with " + hostname;
  cout << msg << endl;

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
  cout << msg << endl;

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
  string msg = "Disconnecting from " + hostname + "...";
  cout << msg << endl;
  vicon_client.Disconnect();
  msg = "Successfully disconnected";
  cout << msg << endl;
  if (!vicon_client.IsConnected().Connected)
    return true;
  return false;
}

int Communicator::findMajorityElement(std::vector<std::size_t>& nums) {
  // If the size of the array is greater than 120, keep only the last 120 elements
  if (nums.size() > 120) {
    nums.erase(nums.begin(), nums.end() - 120);
  }

  int majority = nums[0];
  int count = 1;
  for (int i = 1; i < nums.size(); i++) {
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
  for (int num : nums) {
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
double Communicator::CalculateDeltaTime(const Output_GetTimecode& current, const Output_GetTimecode& previous) {
    // Convert current timecode to total seconds
    double currentTimeInSeconds = current.Hours * 3600.0 +
                                  current.Minutes * 60.0 +
                                  current.Seconds +
                                  current.Frames / static_cast<double>(current.SubFramesPerFrame) +
                                  current.SubFrame / static_cast<double>(current.SubFramesPerFrame * current.SubFramesPerFrame);

    // Convert previous timecode to total seconds
    double previousTimeInSeconds = previous.Hours * 3600.0 +
                                   previous.Minutes * 60.0 +
                                   previous.Seconds +
                                   previous.Frames / static_cast<double>(previous.SubFramesPerFrame) +
                                   previous.SubFrame / static_cast<double>(previous.SubFramesPerFrame * previous.SubFramesPerFrame);

    // Calculate delta time
    return currentTimeInSeconds - previousTimeInSeconds;

}

double Communicator::calculateDistance(const std::vector<double>& a, const std::vector<double>& b) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2));
}

std::vector<int> Communicator::hungarianAlgorithm(const std::vector<std::vector<double>>& costMatrix) {
    std::size_t n = costMatrix.size();
    std::size_t m = costMatrix[0].size();
    std::cout << "  HA " << n << " " << m << std::endl;
    std::vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    std::vector<int> minv(m + 1, std::numeric_limits<int>::max());
    std::vector<bool> used(m + 1, false);

    int i0;
    int j0, j1;
    int delta, cur;
    for (int i = 1; i <= n; ++i) {
        // initialize minv and used
        std::fill(minv.begin(), minv.end(), std::numeric_limits<int>::max());
        std::fill(used.begin(), used.end(), false);

        j0 = 0;
        p[0] = i;
        do {
            used[j0] = true;
            i0 = p[j0];
            
            delta = std::numeric_limits<int>::max();
            for (int j = 1; j <= m; ++j) {
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
            for (int j = 0; j <= m; ++j) {
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
    std::vector<int> result(n);
    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            result[p[j] - 1] = j - 1;
        }
    }
    return result;
}

std::pair<std::vector<std::pair<int, int>>, double> Communicator::findOptimalAssignment(
    const MarkersStruct& current_marker,
    const MarkersStruct& prev_marker) {
    
    std::size_t n = current_marker.indices.size();
    std::size_t m = prev_marker.indices.size();
    std::vector<std::vector<double>> costMatrix(n, std::vector<double>(m));
    std::vector<double> current_marker_pos(3), prev_marker_pos(3);

    // Calculate the cost matrix
    for (int i = 0; i < n; ++i) {
        current_marker_pos = {current_marker.x[i], current_marker.y[i], current_marker.z[i]};
        for (int j = 0; j < m; ++j) {    
            prev_marker_pos = {prev_marker.x[j], prev_marker.y[j], prev_marker.z[j]};
            costMatrix[i][j] = calculateDistance(current_marker_pos, prev_marker_pos);
        }
    }
    
    // // Apply Hungarian Algorithm to find the optimal assignment
    std::vector<int> assignment = hungarianAlgorithm(costMatrix);
    
    // Create the result as pairs of (current_marker index, prev_marker index)
    std::vector<std::pair<int, int>> result;
    double totalCost = 0;
    for (int i = 0; i < n; ++i) {
        result.emplace_back(i, assignment[i]);
        totalCost += costMatrix[i][assignment[i]]; // Sum the cost for each assignment
    }
    
    return std::make_pair(result, totalCost);
}

MarkersStruct Communicator::getPreviousMarkers(){
  if(is_first_frame){
    MarkersStruct prev_markers(0, 0);
    return prev_markers;
  }
  else{
    return Communicator::previous_markers;
  }
}

ViconDataStreamSDK::CPP::Output_GetTimecode Communicator::getPreviousTimecode(){
  if(is_first_frame){
    Output_GetTimecode prev_timecode;
    return Communicator::previous_timecode;
  }
  else{
    return Communicator::previous_timecode;
  }
}

void Communicator::get_frame() {
  if (!vicon_client.IsConnected().Connected) {
    cout << "Not connected to server" << endl;
    // wait 1 sec to try next
    sleep(1);
    return;
  }

  vicon_client.GetFrame();
  Output_GetFrameNumber frame_number = vicon_client.GetFrameNumber();
  std::cout << frame_number.Result << ' ' <<  frame_number.FrameNumber << std::endl;
  Output_GetTimecode timecode = vicon_client.GetTimecode();
  std::cout << timecode.Hours << ":" << timecode.Minutes << ":" << timecode.Seconds << ":" << timecode.Frames << std::endl;

  // std::cout << frame_number.FrameNumber << std::endl;

  // marker_count_total.push_back(vicon_client.GetUnlabeledMarkerCount().MarkerCount); // store marker count for majority element calculation
  // std::size_t marker_count = findMajorityElement(marker_count_total);
  Output_GetUnlabeledMarkerCount unlabeled_marker_count = vicon_client.GetUnlabeledMarkerCount();
  if (unlabeled_marker_count.Result != Result::Success or unlabeled_marker_count.MarkerCount == 0){
    std::cout << "Warning: Unlabeled Markers not found" << unlabeled_marker_count.Result << '\n';
    std::cout << "  " << unlabeled_marker_count.MarkerCount << std::endl;
    return;
  }
  std::size_t marker_count = unlabeled_marker_count.MarkerCount;
  std::cout << "marker count: " << marker_count << std::endl;

  MarkersStruct current_markers(marker_count, frame_number.FrameNumber);
  Output_GetUnlabeledMarkerGlobalTranslation unlabeled_marker_translation;
  for (std::size_t i = 0; i < marker_count; i++) {
    unlabeled_marker_translation = vicon_client.GetUnlabeledMarkerGlobalTranslation(i);
    current_markers.x[i] = unlabeled_marker_translation.translation[0];
    current_markers.y[i] = unlabeled_marker_translation.translation[1];
    current_markers.z[i] = unlabeled_marker_translation.translation[2];
    current_markers.indices[i] = i;
  }

  MarkersStruct prev_markers = Communicator::getPreviousMarkers();
  // Output_GetTimecode prev_timecode = Communicator::getPreviousTimecode();

  if (!is_first_frame){
    double delta_time = 1.0 / 120.0;  //CalculateDeltaTime(timecode, prev_timecode); // TODO

    auto [assignment, totalCost] = findOptimalAssignment(current_markers, prev_markers);
    // std::cout << "Total cost: " << totalCost << std::endl;
    for (const auto& [current_idx, prev_idx] : assignment) {
      current_markers.vx[current_idx] = (current_markers.x[current_idx] - prev_markers.x[prev_idx])/delta_time;
      current_markers.vy[current_idx] = (current_markers.y[current_idx] - prev_markers.y[prev_idx])/delta_time;
      current_markers.vz[current_idx] = (current_markers.z[current_idx] - prev_markers.z[prev_idx])/delta_time;
    }
  }

  Communicator::previous_markers = current_markers;
  // Communicator::previous_timecode = timecode;
  is_first_frame = false; // set to false after first frame
  

  // send position to publisher
  map<string, Publisher>::iterator pub_it;
  boost::mutex::scoped_try_lock lock(mutex);
  const string subject_name = "unlabeled_markers";
  const string segment_name = "positions_velocity";

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

void Communicator::create_publisher(const string subject_name,
                                    const string segment_name) {
  boost::thread(&Communicator::create_publisher_thread, this, subject_name,
                segment_name);
}

void Communicator::create_publisher_thread(const string subject_name,
                                           const string segment_name) {
  std::string topic_name = ns_name + "/" + subject_name + "/" + segment_name;
  std::string key = subject_name + "/" + segment_name;

  string msg = "Creating publisher for segment " + segment_name +
               " from subject " + subject_name;
  cout << msg << endl;

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