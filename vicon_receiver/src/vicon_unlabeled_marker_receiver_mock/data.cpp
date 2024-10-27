#include "vicon_unlabeled_marker_receiver_mock/data.hpp"
#include "vicon_unlabeled_marker_receiver_mock/publisher.hpp"

DataImport::DataImport() {}

void DataImport::fetch_data(unsigned int frame_number,
                            unsigned int segment_index,
                            PositionStruct &current_position) {
  current_position.translation[0] = positions[frame_number][segment_index][0];
  current_position.translation[1] = positions[frame_number][segment_index][1];
  current_position.translation[2] = positions[frame_number][segment_index][2];
  current_position.rotation[0] = rot[frame_number][segment_index][0];
  current_position.rotation[1] = rot[frame_number][segment_index][1];
  current_position.rotation[2] = rot[frame_number][segment_index][2];
  current_position.rotation[3] = rot[frame_number][segment_index][3];
}

void DataImport::load() {
  float temp_positions[1][6][3] = {
      {{1.1823136303447663, 36.59373070071932, -0.15070220641620874},
       {-0.11586563896642983, 60.591261973667656, 0.7435437497910018},
       {0.14706634107515376, 86.57817800605058, 0.030472402101370352},
       {0.3664661709528736, 114.34573219942308, -0.5246268908459925},
       {1.0790936927569983, 141.40869830957436, -0.5480697262501174},
       {1.363622637459471, 171.35692373588466, -0.3537093114006389}}};
  float temp_rot[1][6][4] = {{{0.6221558298889978, 0.33908724249425853,
                               0.35752661622259113, 0.608372159130574},
                              {0.5944494772725165, 0.37482603695207733,
                               0.3783024528839442, 0.602513497886332},
                              {0.5919621705415432, 0.38652917989596586,
                               0.38767058139907706, 0.5915128925512938},
                              {0.5796051393529924, 0.40786258032297074,
                               0.40784255476970893, 0.5756478511440857},
                              {0.5847957965872119, 0.3999396177793901,
                               0.4028261888522024, 0.5794766949577984},
                              {0.5830847317679766, 0.40130318241358165,
                               0.40509337928775174, 0.57867720312885}}};

  for (unsigned int i = 0; i < 6; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      positions[0][i][j] = temp_positions[0][i][j];
    }
    for (unsigned int j = 0; j < 4; j++) {
      rot[0][i][j] = temp_rot[0][i][j];
    }
  }
}