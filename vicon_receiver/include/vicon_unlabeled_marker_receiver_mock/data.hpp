#pragma once
#include "vicon_unlabeled_marker_receiver/publisher.hpp"
#include "vicon_unlabeled_marker_receiver/communicator.hpp"
#include "publisher_mock.hpp"
#include <array>

using namespace ViconReceiver::UnlabeledMarker;

namespace UnlabeledMarker_Mock {
class DataImport {
private:
  std::array<std::array<std::array<float, 3>, 6>, 1> positions;

public:
  DataImport();

  void load();

  void fetch_data(unsigned int, unsigned int, PositionStruct&);
};
} // namespace UnlabeledMarker_Mock
