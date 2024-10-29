// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__STRUCT_H_
#define VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
// Member 'vx'
// Member 'vy'
// Member 'vz'
// Member 'speed'
// Member 'indices'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/MarkersList in the package vicon_receiver.
typedef struct vicon_receiver__msg__MarkersList
{
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
  rosidl_runtime_c__double__Sequence z;
  rosidl_runtime_c__double__Sequence vx;
  rosidl_runtime_c__double__Sequence vy;
  rosidl_runtime_c__double__Sequence vz;
  rosidl_runtime_c__double__Sequence speed;
  rosidl_runtime_c__int32__Sequence indices;
  int32_t frame_number;
} vicon_receiver__msg__MarkersList;

// Struct for a sequence of vicon_receiver__msg__MarkersList.
typedef struct vicon_receiver__msg__MarkersList__Sequence
{
  vicon_receiver__msg__MarkersList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vicon_receiver__msg__MarkersList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__STRUCT_H_
