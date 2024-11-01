#include "vicon_unlabeled_marker_receiver_mock/data.hpp"
#include "vicon_unlabeled_marker_receiver_mock/publisher.hpp"

DataImport::DataImport() {}

void DataImport::fetch_data(unsigned int frame_number,
                            unsigned int segment_index,
                            MarkersStruct &current_position) {
  current_position.translation[0] = positions[frame_number][segment_index][0];
  current_position.translation[1] = positions[frame_number][segment_index][1];
  current_position.translation[2] = positions[frame_number][segment_index][2];
}

void DataImport::load() {
      std::vector<std::vector<float>> temp_new = {
            {1.1823136303447663, 36.59373070071932, -0.15070220641620874},
            {-0.11586563896642983, 60.591261973667656, 0.7435437497910018},
            {0.14706634107515376, 86.57817800605058, 0.030472402101370352},
            {0.3664661709528736, 114.34573219942308, -0.5246268908459925},
            {1.0790936927569983, 141.40869830957436, -0.5480697262501174},
            {1.363622637459471, 171.35692373588466, -0.3537093114006389}};

    std::vector<std::vector<std::vector<float>>> temp_pos;

    // create 6 frames of data
    for (unsigned int i = 0; i < 6; i++) {
        std::vector<std::vector<float>> temp_new_copy = temp_new;
            for (auto& row : temp_new_copy) {
                for (auto& value : row) {
                    value += 0.1;
                }
            }
        temp_pos.push_back(temp_new_copy);
        temp_new = temp_new_copy;
    }

  for(unsigned int k = 0; k < 6; k++){ 
    for (unsigned int i = 0; i < 6; i++) {
      for (unsigned int j = 0; j < 3; j++) {
        positions[0][i][j] = temp_positions[k][i][j];
      }
  }}

}