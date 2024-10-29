// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__TRAITS_HPP_
#define VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__TRAITS_HPP_

#include "vicon_receiver/msg/detail/markers_list__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vicon_receiver::msg::MarkersList>()
{
  return "vicon_receiver::msg::MarkersList";
}

template<>
inline const char * name<vicon_receiver::msg::MarkersList>()
{
  return "vicon_receiver/msg/MarkersList";
}

template<>
struct has_fixed_size<vicon_receiver::msg::MarkersList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vicon_receiver::msg::MarkersList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vicon_receiver::msg::MarkersList>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__TRAITS_HPP_
