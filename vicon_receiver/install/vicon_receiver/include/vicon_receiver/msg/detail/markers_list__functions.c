// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice
#include "vicon_receiver/msg/detail/markers_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


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

bool
vicon_receiver__msg__MarkersList__init(vicon_receiver__msg__MarkersList * msg)
{
  if (!msg) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->x, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->y, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__init(&msg->z, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // vx
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vx, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // vy
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vy, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // vz
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vz, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // speed
  if (!rosidl_runtime_c__double__Sequence__init(&msg->speed, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // indices
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->indices, 0)) {
    vicon_receiver__msg__MarkersList__fini(msg);
    return false;
  }
  // frame_number
  return true;
}

void
vicon_receiver__msg__MarkersList__fini(vicon_receiver__msg__MarkersList * msg)
{
  if (!msg) {
    return;
  }
  // x
  rosidl_runtime_c__double__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__double__Sequence__fini(&msg->y);
  // z
  rosidl_runtime_c__double__Sequence__fini(&msg->z);
  // vx
  rosidl_runtime_c__double__Sequence__fini(&msg->vx);
  // vy
  rosidl_runtime_c__double__Sequence__fini(&msg->vy);
  // vz
  rosidl_runtime_c__double__Sequence__fini(&msg->vz);
  // speed
  rosidl_runtime_c__double__Sequence__fini(&msg->speed);
  // indices
  rosidl_runtime_c__int32__Sequence__fini(&msg->indices);
  // frame_number
}

bool
vicon_receiver__msg__MarkersList__are_equal(const vicon_receiver__msg__MarkersList * lhs, const vicon_receiver__msg__MarkersList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->z), &(rhs->z)))
  {
    return false;
  }
  // vx
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->vx), &(rhs->vx)))
  {
    return false;
  }
  // vy
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->vy), &(rhs->vy)))
  {
    return false;
  }
  // vz
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->vz), &(rhs->vz)))
  {
    return false;
  }
  // speed
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->speed), &(rhs->speed)))
  {
    return false;
  }
  // indices
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->indices), &(rhs->indices)))
  {
    return false;
  }
  // frame_number
  if (lhs->frame_number != rhs->frame_number) {
    return false;
  }
  return true;
}

bool
vicon_receiver__msg__MarkersList__copy(
  const vicon_receiver__msg__MarkersList * input,
  vicon_receiver__msg__MarkersList * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->z), &(output->z)))
  {
    return false;
  }
  // vx
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->vx), &(output->vx)))
  {
    return false;
  }
  // vy
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->vy), &(output->vy)))
  {
    return false;
  }
  // vz
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->vz), &(output->vz)))
  {
    return false;
  }
  // speed
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->speed), &(output->speed)))
  {
    return false;
  }
  // indices
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->indices), &(output->indices)))
  {
    return false;
  }
  // frame_number
  output->frame_number = input->frame_number;
  return true;
}

vicon_receiver__msg__MarkersList *
vicon_receiver__msg__MarkersList__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vicon_receiver__msg__MarkersList * msg = (vicon_receiver__msg__MarkersList *)allocator.allocate(sizeof(vicon_receiver__msg__MarkersList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vicon_receiver__msg__MarkersList));
  bool success = vicon_receiver__msg__MarkersList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vicon_receiver__msg__MarkersList__destroy(vicon_receiver__msg__MarkersList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vicon_receiver__msg__MarkersList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vicon_receiver__msg__MarkersList__Sequence__init(vicon_receiver__msg__MarkersList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vicon_receiver__msg__MarkersList * data = NULL;

  if (size) {
    data = (vicon_receiver__msg__MarkersList *)allocator.zero_allocate(size, sizeof(vicon_receiver__msg__MarkersList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vicon_receiver__msg__MarkersList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vicon_receiver__msg__MarkersList__fini(&data[i - 1]);
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
vicon_receiver__msg__MarkersList__Sequence__fini(vicon_receiver__msg__MarkersList__Sequence * array)
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
      vicon_receiver__msg__MarkersList__fini(&array->data[i]);
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

vicon_receiver__msg__MarkersList__Sequence *
vicon_receiver__msg__MarkersList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vicon_receiver__msg__MarkersList__Sequence * array = (vicon_receiver__msg__MarkersList__Sequence *)allocator.allocate(sizeof(vicon_receiver__msg__MarkersList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vicon_receiver__msg__MarkersList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vicon_receiver__msg__MarkersList__Sequence__destroy(vicon_receiver__msg__MarkersList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vicon_receiver__msg__MarkersList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vicon_receiver__msg__MarkersList__Sequence__are_equal(const vicon_receiver__msg__MarkersList__Sequence * lhs, const vicon_receiver__msg__MarkersList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vicon_receiver__msg__MarkersList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vicon_receiver__msg__MarkersList__Sequence__copy(
  const vicon_receiver__msg__MarkersList__Sequence * input,
  vicon_receiver__msg__MarkersList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vicon_receiver__msg__MarkersList);
    vicon_receiver__msg__MarkersList * data =
      (vicon_receiver__msg__MarkersList *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vicon_receiver__msg__MarkersList__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vicon_receiver__msg__MarkersList__fini(&data[i]);
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
    if (!vicon_receiver__msg__MarkersList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
