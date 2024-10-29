// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vicon_receiver:msg/MarkersList.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__FUNCTIONS_H_
#define VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vicon_receiver/msg/rosidl_generator_c__visibility_control.h"

#include "vicon_receiver/msg/detail/markers_list__struct.h"

/// Initialize msg/MarkersList message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vicon_receiver__msg__MarkersList
 * )) before or use
 * vicon_receiver__msg__MarkersList__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__MarkersList__init(vicon_receiver__msg__MarkersList * msg);

/// Finalize msg/MarkersList message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__MarkersList__fini(vicon_receiver__msg__MarkersList * msg);

/// Create msg/MarkersList message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vicon_receiver__msg__MarkersList__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
vicon_receiver__msg__MarkersList *
vicon_receiver__msg__MarkersList__create();

/// Destroy msg/MarkersList message.
/**
 * It calls
 * vicon_receiver__msg__MarkersList__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__MarkersList__destroy(vicon_receiver__msg__MarkersList * msg);

/// Check for msg/MarkersList message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__MarkersList__are_equal(const vicon_receiver__msg__MarkersList * lhs, const vicon_receiver__msg__MarkersList * rhs);

/// Copy a msg/MarkersList message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__MarkersList__copy(
  const vicon_receiver__msg__MarkersList * input,
  vicon_receiver__msg__MarkersList * output);

/// Initialize array of msg/MarkersList messages.
/**
 * It allocates the memory for the number of elements and calls
 * vicon_receiver__msg__MarkersList__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__MarkersList__Sequence__init(vicon_receiver__msg__MarkersList__Sequence * array, size_t size);

/// Finalize array of msg/MarkersList messages.
/**
 * It calls
 * vicon_receiver__msg__MarkersList__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__MarkersList__Sequence__fini(vicon_receiver__msg__MarkersList__Sequence * array);

/// Create array of msg/MarkersList messages.
/**
 * It allocates the memory for the array and calls
 * vicon_receiver__msg__MarkersList__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
vicon_receiver__msg__MarkersList__Sequence *
vicon_receiver__msg__MarkersList__Sequence__create(size_t size);

/// Destroy array of msg/MarkersList messages.
/**
 * It calls
 * vicon_receiver__msg__MarkersList__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__MarkersList__Sequence__destroy(vicon_receiver__msg__MarkersList__Sequence * array);

/// Check for msg/MarkersList message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__MarkersList__Sequence__are_equal(const vicon_receiver__msg__MarkersList__Sequence * lhs, const vicon_receiver__msg__MarkersList__Sequence * rhs);

/// Copy an array of msg/MarkersList messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__MarkersList__Sequence__copy(
  const vicon_receiver__msg__MarkersList__Sequence * input,
  vicon_receiver__msg__MarkersList__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VICON_RECEIVER__MSG__DETAIL__MARKERS_LIST__FUNCTIONS_H_
