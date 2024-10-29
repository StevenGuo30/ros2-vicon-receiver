// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vicon_receiver:msg/Posture.idl
// generated code does not contain a copyright notice
#include "vicon_receiver/msg/detail/posture__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `segment_name`
// Member `subject_name`
// Member `translation_type`
#include "rosidl_runtime_c/string_functions.h"

bool
vicon_receiver__msg__Posture__init(vicon_receiver__msg__Posture * msg)
{
  if (!msg) {
    return false;
  }
  // x_trans
  // y_trans
  // z_trans
  // x_rot
  // y_rot
  // z_rot
  // w
  // segment_name
  if (!rosidl_runtime_c__String__init(&msg->segment_name)) {
    vicon_receiver__msg__Posture__fini(msg);
    return false;
  }
  // subject_name
  if (!rosidl_runtime_c__String__init(&msg->subject_name)) {
    vicon_receiver__msg__Posture__fini(msg);
    return false;
  }
  // frame_number
  // translation_type
  if (!rosidl_runtime_c__String__init(&msg->translation_type)) {
    vicon_receiver__msg__Posture__fini(msg);
    return false;
  }
  return true;
}

void
vicon_receiver__msg__Posture__fini(vicon_receiver__msg__Posture * msg)
{
  if (!msg) {
    return;
  }
  // x_trans
  // y_trans
  // z_trans
  // x_rot
  // y_rot
  // z_rot
  // w
  // segment_name
  rosidl_runtime_c__String__fini(&msg->segment_name);
  // subject_name
  rosidl_runtime_c__String__fini(&msg->subject_name);
  // frame_number
  // translation_type
  rosidl_runtime_c__String__fini(&msg->translation_type);
}

bool
vicon_receiver__msg__Posture__are_equal(const vicon_receiver__msg__Posture * lhs, const vicon_receiver__msg__Posture * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_trans
  if (lhs->x_trans != rhs->x_trans) {
    return false;
  }
  // y_trans
  if (lhs->y_trans != rhs->y_trans) {
    return false;
  }
  // z_trans
  if (lhs->z_trans != rhs->z_trans) {
    return false;
  }
  // x_rot
  if (lhs->x_rot != rhs->x_rot) {
    return false;
  }
  // y_rot
  if (lhs->y_rot != rhs->y_rot) {
    return false;
  }
  // z_rot
  if (lhs->z_rot != rhs->z_rot) {
    return false;
  }
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  // segment_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->segment_name), &(rhs->segment_name)))
  {
    return false;
  }
  // subject_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->subject_name), &(rhs->subject_name)))
  {
    return false;
  }
  // frame_number
  if (lhs->frame_number != rhs->frame_number) {
    return false;
  }
  // translation_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->translation_type), &(rhs->translation_type)))
  {
    return false;
  }
  return true;
}

bool
vicon_receiver__msg__Posture__copy(
  const vicon_receiver__msg__Posture * input,
  vicon_receiver__msg__Posture * output)
{
  if (!input || !output) {
    return false;
  }
  // x_trans
  output->x_trans = input->x_trans;
  // y_trans
  output->y_trans = input->y_trans;
  // z_trans
  output->z_trans = input->z_trans;
  // x_rot
  output->x_rot = input->x_rot;
  // y_rot
  output->y_rot = input->y_rot;
  // z_rot
  output->z_rot = input->z_rot;
  // w
  output->w = input->w;
  // segment_name
  if (!rosidl_runtime_c__String__copy(
      &(input->segment_name), &(output->segment_name)))
  {
    return false;
  }
  // subject_name
  if (!rosidl_runtime_c__String__copy(
      &(input->subject_name), &(output->subject_name)))
  {
    return false;
  }
  // frame_number
  output->frame_number = input->frame_number;
  // translation_type
  if (!rosidl_runtime_c__String__copy(
      &(input->translation_type), &(output->translation_type)))
  {
    return false;
  }
  return true;
}

vicon_receiver__msg__Posture *
vicon_receiver__msg__Posture__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vicon_receiver__msg__Posture * msg = (vicon_receiver__msg__Posture *)allocator.allocate(sizeof(vicon_receiver__msg__Posture), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vicon_receiver__msg__Posture));
  bool success = vicon_receiver__msg__Posture__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vicon_receiver__msg__Posture__destroy(vicon_receiver__msg__Posture * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vicon_receiver__msg__Posture__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vicon_receiver__msg__Posture__Sequence__init(vicon_receiver__msg__Posture__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vicon_receiver__msg__Posture * data = NULL;

  if (size) {
    data = (vicon_receiver__msg__Posture *)allocator.zero_allocate(size, sizeof(vicon_receiver__msg__Posture), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vicon_receiver__msg__Posture__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vicon_receiver__msg__Posture__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vicon_receiver__msg__Posture__Sequence__fini(vicon_receiver__msg__Posture__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vicon_receiver__msg__Posture__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vicon_receiver__msg__Posture__Sequence *
vicon_receiver__msg__Posture__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vicon_receiver__msg__Posture__Sequence * array = (vicon_receiver__msg__Posture__Sequence *)allocator.allocate(sizeof(vicon_receiver__msg__Posture__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vicon_receiver__msg__Posture__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vicon_receiver__msg__Posture__Sequence__destroy(vicon_receiver__msg__Posture__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vicon_receiver__msg__Posture__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vicon_receiver__msg__Posture__Sequence__are_equal(const vicon_receiver__msg__Posture__Sequence * lhs, const vicon_receiver__msg__Posture__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vicon_receiver__msg__Posture__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vicon_receiver__msg__Posture__Sequence__copy(
  const vicon_receiver__msg__Posture__Sequence * input,
  vicon_receiver__msg__Posture__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vicon_receiver__msg__Posture);
    vicon_receiver__msg__Posture * data =
      (vicon_receiver__msg__Posture *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vicon_receiver__msg__Posture__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vicon_receiver__msg__Posture__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vicon_receiver__msg__Posture__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
