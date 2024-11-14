#pragma once
#include "vicon_unlabeled_marker_receiver/publisher.hpp"
#include "vicon_unlabeled_marker_receiver/communicator.hpp"
#include "publisher_mock.hpp"
#include <array>
#include <thread>

using namespace ViconReceiver::UnlabeledMarker;

namespace UnlabeledMarker_Mock {
class DataImport {
private:
  std::vector<std::vector<std::vector<float>>> positions;

public:
  DataImport();

  void load();

  void fetch_data(unsigned int, unsigned int, PositionStruct_mock&);

  unsigned int get_marker_count(unsigned int);
};
} // namespace UnlabeledMarker_Mock
