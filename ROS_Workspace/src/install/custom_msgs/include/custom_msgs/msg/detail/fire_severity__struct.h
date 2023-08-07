// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'severity'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/FireSeverity in the package custom_msgs.
typedef struct custom_msgs__msg__FireSeverity
{
  rosidl_runtime_c__String severity;
  bool isdetected;
  float fire_x;
  float fire_y;
} custom_msgs__msg__FireSeverity;

// Struct for a sequence of custom_msgs__msg__FireSeverity.
typedef struct custom_msgs__msg__FireSeverity__Sequence
{
  custom_msgs__msg__FireSeverity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__FireSeverity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__FIRE_SEVERITY__STRUCT_H_
