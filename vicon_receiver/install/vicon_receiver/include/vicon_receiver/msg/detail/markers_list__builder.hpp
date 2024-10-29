// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__BUILDER_HPP_
#define VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__BUILDER_HPP_

#include "vicon_receiver/msg/detail/markers_list__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace vicon_receiver
{

namespace msg
{

namespace builder
{

class Init_MarkersList_frame_number
{
public:
  explicit Init_MarkersList_frame_number(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  ::vicon_receiver::msg::MarkersList frame_number(::vicon_receiver::msg::MarkersList::_frame_number_type arg)
  {
    msg_.frame_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_indices
{
public:
  explicit Init_MarkersList_indices(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_frame_number indices(::vicon_receiver::msg::MarkersList::_indices_type arg)
  {
    msg_.indices = std::move(arg);
    return Init_MarkersList_frame_number(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_speed
{
public:
  explicit Init_MarkersList_speed(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_indices speed(::vicon_receiver::msg::MarkersList::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MarkersList_indices(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_vz
{
public:
  explicit Init_MarkersList_vz(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_speed vz(::vicon_receiver::msg::MarkersList::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_MarkersList_speed(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_vy
{
public:
  explicit Init_MarkersList_vy(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_vz vy(::vicon_receiver::msg::MarkersList::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_MarkersList_vz(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_vx
{
public:
  explicit Init_MarkersList_vx(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_vy vx(::vicon_receiver::msg::MarkersList::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_MarkersList_vy(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_z
{
public:
  explicit Init_MarkersList_z(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_vx z(::vicon_receiver::msg::MarkersList::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_MarkersList_vx(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_y
{
public:
  explicit Init_MarkersList_y(::vicon_receiver::msg::MarkersList & msg)
  : msg_(msg)
  {}
  Init_MarkersList_z y(::vicon_receiver::msg::MarkersList::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MarkersList_z(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

class Init_MarkersList_x
{
public:
  Init_MarkersList_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkersList_y x(::vicon_receiver::msg::MarkersList::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MarkersList_y(msg_);
  }

private:
  ::vicon_receiver::msg::MarkersList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vicon_receiver::msg::MarkersList>()
{
  return vicon_receiver::msg::builder::Init_MarkersList_x();
}

}  // namespace vicon_receiver

#endif  // VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__BUILDER_HPP_
