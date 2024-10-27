#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP
#include "rclcpp/rclcpp.hpp"
#include "vicon_receiver/msg/markers_list.hpp"
#include <unistd.h>

namespace ViconReceiver {
namespace UnlabeledMarker {

// Struct used to hold segment data to transmit to the Publisher class.
struct MarkersStruct {
  // Constructor
  MarkersStruct(std::size_t size, unsigned int frame_number)
      : frame_number(frame_number) {
  x.resize(size);
  y.resize(size);
  z.resize(size);
  vx.resize(size);  
  vy.resize(size);  
  vz.resize(size);  
  speed.resize(size); 
  indices.resize(size);
  }

  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> z;
  std::vector<double> vx;  
  std::vector<double> vy;  
  std::vector<double> vz;  
  std::vector<double> speed;  
  std::vector<int> indices;

  unsigned int frame_number;

} typedef MarkersStruct;

// Class that allows segment data to be published in a ROS2 topic.
class Publisher {
private:
  rclcpp::Publisher<vicon_receiver::msg::MarkersList>::SharedPtr publisher_;

public:
  bool is_ready = false;

  Publisher(std::string topic_name, rclcpp::Node *node);

  // Publishes the given position in the ROS2 topic whose name is indicated in
  // the constructor.
  void publish(MarkersStruct &p);
};

} // namespace UnlabeledMarker
} // namespace ViconReceiver

#endif
