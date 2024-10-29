// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vicon_receiver:msg/Posture.idl
// generated code does not contain a copyright notice

#ifndef VICON_RECEIVER__MSG__DETAIL__POSTURE__FUNCTIONS_H_
#define VICON_RECEIVER__MSG__DETAIL__POSTURE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vicon_receiver/msg/rosidl_generator_c__visibility_control.h"

#include "vicon_receiver/msg/detail/posture__struct.h"

/// Initialize msg/Posture message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vicon_receiver__msg__Posture
 * )) before or use
 * vicon_receiver__msg__Posture__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__Posture__init(vicon_receiver__msg__Posture * msg);

/// Finalize msg/Posture message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__Posture__fini(vicon_receiver__msg__Posture * msg);

/// Create msg/Posture message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vicon_receiver__msg__Posture__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
vicon_receiver__msg__Posture *
vicon_receiver__msg__Posture__create();

/// Destroy msg/Posture message.
/**
 * It calls
 * vicon_receiver__msg__Posture__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__Posture__destroy(vicon_receiver__msg__Posture * msg);

/// Check for msg/Posture message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__Posture__are_equal(const vicon_receiver__msg__Posture * lhs, const vicon_receiver__msg__Posture * rhs);

/// Copy a msg/Posture message.
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
vicon_receiver__msg__Posture__copy(
  const vicon_receiver__msg__Posture * input,
  vicon_receiver__msg__Posture * output);

/// Initialize array of msg/Posture messages.
/**
 * It allocates the memory for the number of elements and calls
 * vicon_receiver__msg__Posture__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__Posture__Sequence__init(vicon_receiver__msg__Posture__Sequence * array, size_t size);

/// Finalize array of msg/Posture messages.
/**
 * It calls
 * vicon_receiver__msg__Posture__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__Posture__Sequence__fini(vicon_receiver__msg__Posture__Sequence * array);

/// Create array of msg/Posture messages.
/**
 * It allocates the memory for the array and calls
 * vicon_receiver__msg__Posture__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
vicon_receiver__msg__Posture__Sequence *
vicon_receiver__msg__Posture__Sequence__create(size_t size);

/// Destroy array of msg/Posture messages.
/**
 * It calls
 * vicon_receiver__msg__Posture__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
void
vicon_receiver__msg__Posture__Sequence__destroy(vicon_receiver__msg__Posture__Sequence * array);

/// Check for msg/Posture message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vicon_receiver
bool
vicon_receiver__msg__Posture__Sequence__are_equal(const vicon_receiver__msg__Posture__Sequence * lhs, const vicon_receiver__msg__Posture__Sequence * rhs);

/// Copy an array of msg/Posture messages.
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
vicon_receiver__msg__Posture__Sequence__copy(
  const vicon_receiver__msg__Posture__Sequence * input,
  vicon_receiver__msg__Posture__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VICON_RECEIVER__MSG__DETAIL__POSTURE__FUNCTIONS_H_
