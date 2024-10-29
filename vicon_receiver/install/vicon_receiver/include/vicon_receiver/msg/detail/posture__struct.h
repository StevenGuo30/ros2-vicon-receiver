// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vicon_receiver:msg/Posture.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__POSTURE__STRUCT_H_
#define VICON_RECEIVER__MSG__DETAIL__POSTURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'segment_name'
// Member 'subject_name'
// Member 'translation_type'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Posture in the package vicon_receiver.
typedef struct vicon_receiver__msg__Posture
{
  float x_trans;
  float y_trans;
  float z_trans;
  float x_rot;
  float y_rot;
  float z_rot;
  float w;
  rosidl_runtime_c__String segment_name;
  rosidl_runtime_c__String subject_name;
  int32_t frame_number;
  rosidl_runtime_c__String translation_type;
} vicon_receiver__msg__Posture;

// Struct for a sequence of vicon_receiver__msg__Posture.
typedef struct vicon_receiver__msg__Posture__Sequence
{
  vicon_receiver__msg__Posture * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vicon_receiver__msg__Posture__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VICON_RECEIVER__MSG__DETAIL__POSTURE__STRUCT_H_
