// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vicon_receiver:msg/Posture.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__POSTURE__TRAITS_HPP_
#define VICON_RECEIVER__MSG__DETAIL__POSTURE__TRAITS_HPP_

#include "vicon_receiver/msg/detail/posture__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vicon_receiver::msg::Posture>()
{
  return "vicon_receiver::msg::Posture";
}

template<>
inline const char * name<vicon_receiver::msg::Posture>()
{
  return "vicon_receiver/msg/Posture";
}

template<>
struct has_fixed_size<vicon_receiver::msg::Posture>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vicon_receiver::msg::Posture>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vicon_receiver::msg::Posture>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VICON_RECEIVER__MSG__DETAIL__POSTURE__TRAITS_HPP_
