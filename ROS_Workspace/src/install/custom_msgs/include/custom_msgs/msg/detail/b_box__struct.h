// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/BBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__B_BOX__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__B_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_label'
// Member 'box_id'
#include "std_msgs/msg/detail/string__struct.h"

// Struct defined in msg/BBox in the package custom_msgs.
typedef struct custom_msgs__msg__BBox
{
  uint32_t top_left_x;
  uint32_t top_left_y;
  uint32_t bottom_right_x;
  uint32_t bottom_right_y;
  float score;
  std_msgs__msg__String class_label;
  float px_to_mm;
  float px_to_ms;
  uint64_t timestamp_ms;
  std_msgs__msg__String box_id;
} custom_msgs__msg__BBox;

// Struct for a sequence of custom_msgs__msg__BBox.
typedef struct custom_msgs__msg__BBox__Sequence
{
  custom_msgs__msg__BBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__BBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__B_BOX__STRUCT_H_
