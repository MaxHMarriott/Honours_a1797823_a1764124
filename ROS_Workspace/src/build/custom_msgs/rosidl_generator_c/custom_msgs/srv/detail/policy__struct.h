// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:srv/Policy.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__SRV__DETAIL__POLICY__STRUCT_H_
#define CUSTOM_MSGS__SRV__DETAIL__POLICY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "custom_msgs/msg/detail/pose__struct.h"
// Member 'eta'
#include "custom_msgs/msg/detail/float__struct.h"

// Struct defined in srv/Policy in the package custom_msgs.
typedef struct custom_msgs__srv__Policy_Request
{
  custom_msgs__msg__Pose pose;
  custom_msgs__msg__Float eta;
} custom_msgs__srv__Policy_Request;

// Struct for a sequence of custom_msgs__srv__Policy_Request.
typedef struct custom_msgs__srv__Policy_Request__Sequence
{
  custom_msgs__srv__Policy_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__srv__Policy_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'ack'
#include "custom_msgs/msg/detail/string__struct.h"

// Struct defined in srv/Policy in the package custom_msgs.
typedef struct custom_msgs__srv__Policy_Response
{
  custom_msgs__msg__String ack;
} custom_msgs__srv__Policy_Response;

// Struct for a sequence of custom_msgs__srv__Policy_Response.
typedef struct custom_msgs__srv__Policy_Response__Sequence
{
  custom_msgs__srv__Policy_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__srv__Policy_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__SRV__DETAIL__POLICY__STRUCT_H_
