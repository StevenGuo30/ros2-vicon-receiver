// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vicon_receiver:msg/Posture.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__POSTURE__BUILDER_HPP_
#define VICON_RECEIVER__MSG__DETAIL__POSTURE__BUILDER_HPP_

#include "vicon_receiver/msg/detail/posture__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace vicon_receiver
{

namespace msg
{

namespace builder
{

class Init_Posture_translation_type
{
public:
  explicit Init_Posture_translation_type(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  ::vicon_receiver::msg::Posture translation_type(::vicon_receiver::msg::Posture::_translation_type_type arg)
  {
    msg_.translation_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_frame_number
{
public:
  explicit Init_Posture_frame_number(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_translation_type frame_number(::vicon_receiver::msg::Posture::_frame_number_type arg)
  {
    msg_.frame_number = std::move(arg);
    return Init_Posture_translation_type(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_subject_name
{
public:
  explicit Init_Posture_subject_name(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_frame_number subject_name(::vicon_receiver::msg::Posture::_subject_name_type arg)
  {
    msg_.subject_name = std::move(arg);
    return Init_Posture_frame_number(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_segment_name
{
public:
  explicit Init_Posture_segment_name(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_subject_name segment_name(::vicon_receiver::msg::Posture::_segment_name_type arg)
  {
    msg_.segment_name = std::move(arg);
    return Init_Posture_subject_name(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_w
{
public:
  explicit Init_Posture_w(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_segment_name w(::vicon_receiver::msg::Posture::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_Posture_segment_name(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_z_rot
{
public:
  explicit Init_Posture_z_rot(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_w z_rot(::vicon_receiver::msg::Posture::_z_rot_type arg)
  {
    msg_.z_rot = std::move(arg);
    return Init_Posture_w(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_y_rot
{
public:
  explicit Init_Posture_y_rot(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_z_rot y_rot(::vicon_receiver::msg::Posture::_y_rot_type arg)
  {
    msg_.y_rot = std::move(arg);
    return Init_Posture_z_rot(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_x_rot
{
public:
  explicit Init_Posture_x_rot(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_y_rot x_rot(::vicon_receiver::msg::Posture::_x_rot_type arg)
  {
    msg_.x_rot = std::move(arg);
    return Init_Posture_y_rot(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_z_trans
{
public:
  explicit Init_Posture_z_trans(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_x_rot z_trans(::vicon_receiver::msg::Posture::_z_trans_type arg)
  {
    msg_.z_trans = std::move(arg);
    return Init_Posture_x_rot(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_y_trans
{
public:
  explicit Init_Posture_y_trans(::vicon_receiver::msg::Posture & msg)
  : msg_(msg)
  {}
  Init_Posture_z_trans y_trans(::vicon_receiver::msg::Posture::_y_trans_type arg)
  {
    msg_.y_trans = std::move(arg);
    return Init_Posture_z_trans(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

class Init_Posture_x_trans
{
public:
  Init_Posture_x_trans()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Posture_y_trans x_trans(::vicon_receiver::msg::Posture::_x_trans_type arg)
  {
    msg_.x_trans = std::move(arg);
    return Init_Posture_y_trans(msg_);
  }

private:
  ::vicon_receiver::msg::Posture msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vicon_receiver::msg::Posture>()
{
  return vicon_receiver::msg::builder::Init_Posture_x_trans();
}

}  // namespace vicon_receiver

#endif  // VICON_RECEIVER__MSG__DETAIL__POSTURE__BUILDER_HPP_
