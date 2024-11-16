#pragma once

#include "DataStreamClient.h"
#include "rclcpp/rclcpp.hpp"
#include <boost/thread.hpp>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <limits>

#include "vicon_unlabeled_marker_receiver/publisher.hpp"
#include "utility/data_structure/fixed_size_queue.hpp"

namespace ViconReceiver {
namespace UnlabeledMarker {

// Main Node class
class Communicator : public rclcpp::Node {
private:
  ViconDataStreamSDK::CPP::Client vicon_client;
  std::string hostname;
  unsigned int buffer_size;
  std::string ns_name;
  std::map<std::string, Publisher> pub_map;
  boost::mutex mutex;

  MarkersStruct previous_markers;
  double previous_frame_time = 0.0;
  std::size_t marker_count;

  bool flag_initialized = false;

public:

  Communicator();

  // Initialises the connection to the DataStream server
  bool connect();

  // Stops the current connection to a DataStream server (if any).
  bool disconnect();

  // Main loop that request frames from the currently connected DataStream
  // server and send the received segment data to the Publisher class.
  void get_frame();

  // functions to create a segment publisher in a new thread
  void create_publisher(const std::string subject_name, const std::string segment_name);
  void create_publisher_thread(const std::string subject_name,
                               const std::string segment_name);

  bool fetch_markers(MarkersStruct&);

  template <typename T>
  std::size_t find_majority_element(const std::deque<T>&);

  std::pair<std::vector<std::pair<std::size_t, std::size_t>>, double> find_optimal_assignment(
    const MarkersStruct& current_marker,
    const MarkersStruct& prev_marker);

};

} // namespace UnlabeledMarker
} // namespace ViconReceiver
