// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__STRUCT_HPP_
#define VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__vicon_receiver__msg__MarkersList __attribute__((deprecated))
#else
# define DEPRECATED__vicon_receiver__msg__MarkersList __declspec(deprecated)
#endif

namespace vicon_receiver
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MarkersList_
{
  using Type = MarkersList_<ContainerAllocator>;

  explicit MarkersList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_number = 0l;
    }
  }

  explicit MarkersList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_number = 0l;
    }
  }

  // field types and members
  using _x_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _x_type x;
  using _y_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _y_type y;
  using _z_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _z_type z;
  using _vx_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _vx_type vx;
  using _vy_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _vy_type vy;
  using _vz_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _vz_type vz;
  using _speed_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _speed_type speed;
  using _indices_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _indices_type indices;
  using _frame_number_type =
    int32_t;
  _frame_number_type frame_number;

  // setters for named parameter idiom
  Type & set__x(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__vx(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__speed(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__indices(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->indices = _arg;
    return *this;
  }
  Type & set__frame_number(
    const int32_t & _arg)
  {
    this->frame_number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vicon_receiver::msg::MarkersList_<ContainerAllocator> *;
  using ConstRawPtr =
    const vicon_receiver::msg::MarkersList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vicon_receiver::msg::MarkersList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vicon_receiver::msg::MarkersList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vicon_receiver__msg__MarkersList
    std::shared_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vicon_receiver__msg__MarkersList
    std::shared_ptr<vicon_receiver::msg::MarkersList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MarkersList_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->indices != other.indices) {
      return false;
    }
    if (this->frame_number != other.frame_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const MarkersList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MarkersList_

// alias to use template instance with default allocator
using MarkersList =
  vicon_receiver::msg::MarkersList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vicon_receiver

#endif  // VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__STRUCT_HPP_
