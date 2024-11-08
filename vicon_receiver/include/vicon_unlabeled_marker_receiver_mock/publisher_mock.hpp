#if !defined(PUBLISHER_MOCK_HPP)
#define PUBLISHER_MOCK_HPP
#include "rclcpp/rclcpp.hpp"
#include "vicon_receiver/msg/posture.hpp"
#include "vicon_unlabeled_marker_receiver/publisher.hpp"
#include "data.hpp"
#include <unistd.h>

namespace UnlabeledMarker_Mock {
// Struct used to hold segment data to transmit to the Publisher class.
struct PositionStruct_mock {
  double Translation[3];
  std::string subject_name;
  std::string segment_name;
  std::string translation_type;
  unsigned int frame_number;

} typedef PositionStruct_mock;

} // namespace UnlabeledMarker_Mock

#endif