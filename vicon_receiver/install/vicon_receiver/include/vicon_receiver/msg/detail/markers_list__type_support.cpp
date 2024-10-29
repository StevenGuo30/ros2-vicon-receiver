// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vicon_receiver/msg/detail/markers_list__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vicon_receiver
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MarkersList_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vicon_receiver::msg::MarkersList(_init);
}

void MarkersList_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vicon_receiver::msg::MarkersList *>(message_memory);
  typed_message->~MarkersList();
}

size_t size_function__MarkersList__x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__z(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__z(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__z(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__z(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__vx(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__vx(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__vx(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__vx(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__vy(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__vy(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__vy(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__vy(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__vz(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__vz(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__vz(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__vz(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__speed(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__speed(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__speed(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__speed(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MarkersList__indices(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MarkersList__indices(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MarkersList__indices(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void resize_function__MarkersList__indices(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MarkersList_message_member_array[9] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, x),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__x,  // size() function pointer
    get_const_function__MarkersList__x,  // get_const(index) function pointer
    get_function__MarkersList__x,  // get(index) function pointer
    resize_function__MarkersList__x  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, y),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__y,  // size() function pointer
    get_const_function__MarkersList__y,  // get_const(index) function pointer
    get_function__MarkersList__y,  // get(index) function pointer
    resize_function__MarkersList__y  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, z),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__z,  // size() function pointer
    get_const_function__MarkersList__z,  // get_const(index) function pointer
    get_function__MarkersList__z,  // get(index) function pointer
    resize_function__MarkersList__z  // resize(index) function pointer
  },
  {
    "vx",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, vx),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__vx,  // size() function pointer
    get_const_function__MarkersList__vx,  // get_const(index) function pointer
    get_function__MarkersList__vx,  // get(index) function pointer
    resize_function__MarkersList__vx  // resize(index) function pointer
  },
  {
    "vy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, vy),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__vy,  // size() function pointer
    get_const_function__MarkersList__vy,  // get_const(index) function pointer
    get_function__MarkersList__vy,  // get(index) function pointer
    resize_function__MarkersList__vy  // resize(index) function pointer
  },
  {
    "vz",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, vz),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__vz,  // size() function pointer
    get_const_function__MarkersList__vz,  // get_const(index) function pointer
    get_function__MarkersList__vz,  // get(index) function pointer
    resize_function__MarkersList__vz  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, speed),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__speed,  // size() function pointer
    get_const_function__MarkersList__speed,  // get_const(index) function pointer
    get_function__MarkersList__speed,  // get(index) function pointer
    resize_function__MarkersList__speed  // resize(index) function pointer
  },
  {
    "indices",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, indices),  // bytes offset in struct
    nullptr,  // default value
    size_function__MarkersList__indices,  // size() function pointer
    get_const_function__MarkersList__indices,  // get_const(index) function pointer
    get_function__MarkersList__indices,  // get(index) function pointer
    resize_function__MarkersList__indices  // resize(index) function pointer
  },
  {
    "frame_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver::msg::MarkersList, frame_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MarkersList_message_members = {
  "vicon_receiver::msg",  // message namespace
  "MarkersList",  // message name
  9,  // number of fields
  sizeof(vicon_receiver::msg::MarkersList),
  MarkersList_message_member_array,  // message members
  MarkersList_init_function,  // function to initialize message memory (memory has to be allocated)
  MarkersList_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MarkersList_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MarkersList_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vicon_receiver


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vicon_receiver::msg::MarkersList>()
{
  return &::vicon_receiver::msg::rosidl_typesupport_introspection_cpp::MarkersList_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vicon_receiver, msg, MarkersList)() {
  return &::vicon_receiver::msg::rosidl_typesupport_introspection_cpp::MarkersList_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
