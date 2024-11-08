#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP
#include "rclcpp/rclcpp.hpp"
#include "vicon_receiver/msg/posture.hpp"
#include "vicon_unlabeled_marker_receiver/publisher.hpp"
#include "vicon_unlabeled_marker_receiver_mock/data.hpp"
#include <unistd.h>

namespace UnlabeledMarker_Mock {
// Struct used to hold segment data to transmit to the Publisher class.
struct PositionStruct {
  double translation[3];
//   double rotation[4];
  std::string subject_name;
  std::string segment_name;
  std::string translation_type;
  unsigned int frame_number;

} typedef PositionStruct;

} // namespace UnlabeledMarker_Mock

#endif