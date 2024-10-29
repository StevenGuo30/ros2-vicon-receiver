// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vicon_receiver/msg/detail/markers_list__rosidl_typesupport_introspection_c.h"
#include "vicon_receiver/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vicon_receiver/msg/detail/markers_list__functions.h"
#include "vicon_receiver/msg/detail/markers_list__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
// Member `vx`
// Member `vy`
// Member `vz`
// Member `speed`
// Member `indices`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MarkersList__rosidl_typesupport_introspection_c__MarkersList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vicon_receiver__msg__MarkersList__init(message_memory);
}

void MarkersList__rosidl_typesupport_introspection_c__MarkersList_fini_function(void * message_memory)
{
  vicon_receiver__msg__MarkersList__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_member_array[9] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, vx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, vy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, vz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "indices",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, indices),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vicon_receiver__msg__MarkersList, frame_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_members = {
  "vicon_receiver__msg",  // message namespace
  "MarkersList",  // message name
  9,  // number of fields
  sizeof(vicon_receiver__msg__MarkersList),
  MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_member_array,  // message members
  MarkersList__rosidl_typesupport_introspection_c__MarkersList_init_function,  // function to initialize message memory (memory has to be allocated)
  MarkersList__rosidl_typesupport_introspection_c__MarkersList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_type_support_handle = {
  0,
  &MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vicon_receiver
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vicon_receiver, msg, MarkersList)() {
  if (!MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_type_support_handle.typesupport_identifier) {
    MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MarkersList__rosidl_typesupport_introspection_c__MarkersList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
