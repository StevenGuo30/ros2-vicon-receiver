#pragma once
#include "publisher.hpp"
#include <array>

class DataImport {
private:
  std::array<std::array<std::array<float, 3>, 6>, 1> positions;

public:
  DataImport();

  void load();

  void fetch_data(unsigned int, unsigned int, MarkersStruct &);
};
