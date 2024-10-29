// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vicon_receiver:msg/Posture.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__POSTURE__STRUCT_HPP_
#define VICON_RECEIVER__MSG__DETAIL__POSTURE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__vicon_receiver__msg__Posture __attribute__((deprecated))
#else
# define DEPRECATED__vicon_receiver__msg__Posture __declspec(deprecated)
#endif

namespace vicon_receiver
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Posture_
{
  using Type = Posture_<ContainerAllocator>;

  explicit Posture_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_trans = 0.0f;
      this->y_trans = 0.0f;
      this->z_trans = 0.0f;
      this->x_rot = 0.0f;
      this->y_rot = 0.0f;
      this->z_rot = 0.0f;
      this->w = 0.0f;
      this->segment_name = "";
      this->subject_name = "";
      this->frame_number = 0l;
      this->translation_type = "";
    }
  }

  explicit Posture_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : segment_name(_alloc),
    subject_name(_alloc),
    translation_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_trans = 0.0f;
      this->y_trans = 0.0f;
      this->z_trans = 0.0f;
      this->x_rot = 0.0f;
      this->y_rot = 0.0f;
      this->z_rot = 0.0f;
      this->w = 0.0f;
      this->segment_name = "";
      this->subject_name = "";
      this->frame_number = 0l;
      this->translation_type = "";
    }
  }

  // field types and members
  using _x_trans_type =
    float;
  _x_trans_type x_trans;
  using _y_trans_type =
    float;
  _y_trans_type y_trans;
  using _z_trans_type =
    float;
  _z_trans_type z_trans;
  using _x_rot_type =
    float;
  _x_rot_type x_rot;
  using _y_rot_type =
    float;
  _y_rot_type y_rot;
  using _z_rot_type =
    float;
  _z_rot_type z_rot;
  using _w_type =
    float;
  _w_type w;
  using _segment_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _segment_name_type segment_name;
  using _subject_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _subject_name_type subject_name;
  using _frame_number_type =
    int32_t;
  _frame_number_type frame_number;
  using _translation_type_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _translation_type_type translation_type;

  // setters for named parameter idiom
  Type & set__x_trans(
    const float & _arg)
  {
    this->x_trans = _arg;
    return *this;
  }
  Type & set__y_trans(
    const float & _arg)
  {
    this->y_trans = _arg;
    return *this;
  }
  Type & set__z_trans(
    const float & _arg)
  {
    this->z_trans = _arg;
    return *this;
  }
  Type & set__x_rot(
    const float & _arg)
  {
    this->x_rot = _arg;
    return *this;
  }
  Type & set__y_rot(
    const float & _arg)
  {
    this->y_rot = _arg;
    return *this;
  }
  Type & set__z_rot(
    const float & _arg)
  {
    this->z_rot = _arg;
    return *this;
  }
  Type & set__w(
    const float & _arg)
  {
    this->w = _arg;
    return *this;
  }
  Type & set__segment_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->segment_name = _arg;
    return *this;
  }
  Type & set__subject_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->subject_name = _arg;
    return *this;
  }
  Type & set__frame_number(
    const int32_t & _arg)
  {
    this->frame_number = _arg;
    return *this;
  }
  Type & set__translation_type(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->translation_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vicon_receiver::msg::Posture_<ContainerAllocator> *;
  using ConstRawPtr =
    const vicon_receiver::msg::Posture_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vicon_receiver::msg::Posture_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vicon_receiver::msg::Posture_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vicon_receiver::msg::Posture_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vicon_receiver::msg::Posture_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vicon_receiver::msg::Posture_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vicon_receiver::msg::Posture_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vicon_receiver::msg::Posture_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vicon_receiver::msg::Posture_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vicon_receiver__msg__Posture
    std::shared_ptr<vicon_receiver::msg::Posture_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vicon_receiver__msg__Posture
    std::shared_ptr<vicon_receiver::msg::Posture_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Posture_ & other) const
  {
    if (this->x_trans != other.x_trans) {
      return false;
    }
    if (this->y_trans != other.y_trans) {
      return false;
    }
    if (this->z_trans != other.z_trans) {
      return false;
    }
    if (this->x_rot != other.x_rot) {
      return false;
    }
    if (this->y_rot != other.y_rot) {
      return false;
    }
    if (this->z_rot != other.z_rot) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    if (this->segment_name != other.segment_name) {
      return false;
    }
    if (this->subject_name != other.subject_name) {
      return false;
    }
    if (this->frame_number != other.frame_number) {
      return false;
    }
    if (this->translation_type != other.translation_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const Posture_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Posture_

// alias to use template instance with default allocator
using Posture =
  vicon_receiver::msg::Posture_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vicon_receiver

#endif  // VICON_RECEIVER__MSG__DETAIL__POSTURE__STRUCT_HPP_
