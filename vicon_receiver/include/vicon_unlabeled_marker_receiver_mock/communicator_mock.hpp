#pragma once

#include "data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "vicon_unlabeled_marker_receiver/communicator.hpp"

namespace UnlabeledMarker_Mock {
DataImport data;
unsigned int frame_number_mock = 0UL;
unsigned int frame_number = 0UL;
} // namespace UnlabeledMarker_Mock
