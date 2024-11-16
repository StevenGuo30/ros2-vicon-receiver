#pragma once

#include "DataStreamClient.h"
#include "rclcpp/rclcpp.hpp"
#include "vicon_unlabeled_marker_receiver/publisher.hpp"
#include <boost/thread.hpp>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

namespace ViconReceiver {
namespace UnlabeledMarker {

// Main Node class
class Communicator : public rclcpp::Node {
private:
  ViconDataStreamSDK::CPP::Client vicon_client;
  string hostname;
  unsigned int buffer_size;
  string ns_name;
  map<string, Publisher> pub_map;
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
  void create_publisher(const string subject_name, const string segment_name);
  void create_publisher_thread(const string subject_name,
                               const string segment_name);

  bool fetch_markers(MarkersStruct&);
  int findMajorityElement(std::vector<std::size_t>& nums);
  inline double frame_delta_time(double& current_frame_time);
  inline double calculateDistance(const std::vector<double>& a, const std::vector<double>& b);
  std::vector<int> hungarianAlgorithm(const std::vector<std::vector<double>>& costMatrix);
  std::pair<std::vector<std::pair<int, int>>, double> findOptimalAssignment(
    const MarkersStruct& current_marker,
    const MarkersStruct& prev_marker); 
};

} // namespace UnlabeledMarker
} // namespace ViconReceiver
