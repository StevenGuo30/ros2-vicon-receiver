#include "vicon_unlabeled_marker_receiver_mock/publisher.hpp"

namespace ViconReceiver {
namespace UnlabeledMarker {

Publisher::Publisher(std::string topic_name, rclcpp::Node *node) {
  publisher_ =
      node->create_publisher<vicon_receiver::msg::MarkersList>(topic_name, 20);
  is_ready = true;
}

void Publisher::publish(MarkersStruct &p) {
  auto msg = std::make_shared<vicon_receiver::msg::MarkersList>();
  msg->x = std::move(p.x);
  msg->y = std::move(p.y);
  msg->z = std::move(p.z);

  msg->vx = std::move(p.vx);
  msg->vy = std::move(p.vy);
  msg->vz = std::move(p.vz);
  msg->speed = std::move(p.speed);
  
  msg->indices = std::move(p.indices);
  msg->frame_number = p.frame_number;
  publisher_->publish(*msg);
}

} // namespace UnlabeledMarker
} // namespace ViconReceiver