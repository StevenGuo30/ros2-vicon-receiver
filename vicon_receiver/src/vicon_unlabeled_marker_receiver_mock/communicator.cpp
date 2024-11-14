#include "vicon_unlabeled_marker_receiver_mock/communicator_mock.hpp"

using namespace ViconDataStreamSDK::CPP;
using namespace UnlabeledMarker_Mock;

namespace ViconReceiver {
namespace UnlabeledMarker {

bool is_first_frame = true;
std::vector<std::size_t> marker_count_total;

Communicator::Communicator() : Node("vicon") {
  // get parameters
  this->declare_parameter<int>("buffer_size", 200);
  this->declare_parameter<std::string>("namespace", "vicon_mock");
  this->get_parameter("buffer_size", buffer_size);
  this->get_parameter("namespace", ns_name);
}

bool Communicator::connect() {
  // connect to server
  string msg = "Connecting to vicon-mock ...";
  cout << msg << endl;
  msg = "Connection successfully established with vicon-mock";
  cout << msg << endl;

  data.load();

  if(is_first_frame){
    frame_number = 0;
    frame_number_mock = 0;
  }

  msg = "Initialization complete";
  cout << msg << endl;

  return true;
}

bool Communicator::disconnect() {
  sleep(1);
  string msg = "Disconnecting from vicon-mock";
  cout << msg << endl;
  msg = "Successfully disconnected";
  cout << msg << endl;
  return true;
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

  std::cout << "Majority element: " << majority << std::endl;
  return majority;
}

// Calculate the time difference between two timecodes
double Communicator::frame_delta_time(double current_frame_time){
    double delta_time = 0.00f;
    delta_time = current_frame_time - Communicator::previous_frame_time;
    return delta_time;
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

void Communicator::get_frame() {
  const auto now = std::chrono::system_clock::now();
  double current_frame_time = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
  // std::cout << "Current frame time: " << current_frame_time << " ms" << std::endl;

  // Output_GetUnlabeledMarkerCount unlabeled_marker_count = vicon_client.GetUnlabeledMarkerCount();
  // if (unlabeled_marker_count.Result != Result::Success or unlabeled_marker_count.MarkerCount == 0){
  //   std::cout << "Warning: Unlabeled Markers not found" << unlabeled_marker_count.Result << '\n';
  //   std::cout << "  " << unlabeled_marker_count.MarkerCount << std::endl;
  //   return;
  // }
  std::size_t marker_count_now = data.get_marker_count(frame_number_mock); //data.positions[1].size(),we have 6 unlabeled markers;
  marker_count_total.push_back(marker_count_now); // store marker count for majority element calculation
  std::size_t marker_count = findMajorityElement(marker_count_total);
  std::cout << "marker_count: " << marker_count << std::endl;

  if(marker_count_now != marker_count){
    std::cout << "Warning: flickering" << '\n';
    frame_number_mock=0;
    return;
  }
  
  MarkersStruct current_markers(marker_count, frame_number);
  std::cout << "frame_number: " << current_markers.frame_number << std::endl;
  std::cout << "frame_number_mock: " << frame_number_mock << std::endl;
  PositionStruct_mock unlabeled_marker_translation;
  for (std::size_t i = 0; i < marker_count; i++) {
    data.fetch_data(frame_number_mock, i, unlabeled_marker_translation);
    current_markers.x[i] = unlabeled_marker_translation.Translation[0];
    current_markers.y[i] = unlabeled_marker_translation.Translation[1];
    current_markers.z[i] = unlabeled_marker_translation.Translation[2];
    current_markers.indices[i] = i;
  }

  MarkersStruct prev_markers = Communicator::getPreviousMarkers();

  if(frame_number_mock < 7){
    frame_number_mock++;
  }
  else{
    frame_number_mock = 0;
  }
  frame_number++;//increment frame number

  if (!is_first_frame){
    double delta_time = Communicator::frame_delta_time(current_frame_time) / 1000.0; // convert to seconds
    if (delta_time == 0.0){
      std::cout << "Warning: Delta time is zero" << std::endl;
      return;
    }
    std::cout << "Delta time: " << delta_time << " ms" << std::endl;

    auto [assignment, totalCost] = findOptimalAssignment(current_markers, prev_markers);
    std::cout << "Not freeze here" << std::endl;
    std::cout << "Total cost: " << totalCost << std::endl;
    for (const auto& [current_idx, prev_idx] : assignment) {
      current_markers.vx[current_idx] = (current_markers.x[current_idx] - prev_markers.x[prev_idx])/delta_time;
      current_markers.vy[current_idx] = (current_markers.y[current_idx] - prev_markers.y[prev_idx])/delta_time;
      current_markers.vz[current_idx] = (current_markers.z[current_idx] - prev_markers.z[prev_idx])/delta_time;
    }
  }

  Communicator::previous_markers = current_markers;
  std::cout << "Previous markers count:" << Communicator::previous_markers.indices.back() << std::endl;
  Communicator::previous_frame_time = current_frame_time;
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