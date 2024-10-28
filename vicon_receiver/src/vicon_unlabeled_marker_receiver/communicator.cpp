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

int findMajorityElement(std::vector<std::size_t>& nums) {
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
double CalculateDeltaTime(Output_GetTimecode& current, Output_GetTimecode& previous) {
    int delta_seconds = (current.Seconds) - (previous.Seconds);
    
    int delta_frames = (current.Frames) - (previous.Frames);

    if (delta_frames < 0) {
        delta_frames += 1.0/120。0;
        delta_seconds -= 1;  
    }

    double delta_time = delta_seconds 
                        + (delta_frames) / (1。0/120。0);

    return delta_time;
}

// double calculateDistance(const std::vector<double>& a, const std::vector<double>& b) {
//     return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2));
// }

void Communicator::get_frame() {
  if (!vicon_client.IsConnected().Connected) {
    cout << "Not connected to server" << endl;
    // wait 1 sec to try next
    sleep(1);
    return;
  }

  vicon_client.GetFrame();
  Output_GetFrameNumber frame_number = vicon_client.GetFrameNumber();
  Output_GetTimecode timecode = vicon_client.GetTimecode();
  marker_count_total.push_back(vicon_client.GetUnlabeledMarkerCount().MarkerCount); // store marker count for majority element calculation
  std::size_t marker_count = findMajorityElement(marker_count_total);

  MarkersStruct current_markers(marker_count, frame_number.FrameNumber);
  for (std::size_t i = 0; i < marker_count; i++) {
    auto translation =
        vicon_client.GetUnlabeledMarkerGlobalTranslation(i).Translation;
    current_markers.x[i] = translation[0];
    current_markers.y[i] = translation[1];
    current_markers.z[i] = translation[2];
    current_markers.indices[i] = i;
  }

  MarkersStruct prev_markers = getPreviousMarkers();
  Output_GetTimecode prev_timecode = getPreviousTimecode();

  if (!is_first_frame){
    double delta_time = CalculateDeltaTime(timecode, prev_timecode);
    for (std::size_t i = 0; i < marker_count; i++) {
        double dx = current_markers.x[i] - prev_markers.x[i];
        double dy = current_markers.y[i] - prev_markers.y[i];
        double dz = current_markers.z[i] - prev_markers.z[i];

        current_markers.vx[i] = dx / delta_time;
        current_markers.vy[i] = dy / delta_time;
        current_markers.vz[i] = dz / delta_time;        
        double speed = sqrt(dx * dx + dy * dy + dz * dz) / delta_time; 
    }
  }


  // send position to publisher
  map<string, Publisher>::iterator pub_it;
  boost::mutex::scoped_try_lock lock(mutex);
  const string subject_name = "unlabeled_markers";
  const string segment_name = "positions_velocities";

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