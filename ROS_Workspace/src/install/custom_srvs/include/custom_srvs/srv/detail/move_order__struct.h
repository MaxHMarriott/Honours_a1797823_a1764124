// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_srvs:srv/MoveOrder.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SRVS__SRV__DETAIL__MOVE_ORDER__STRUCT_H_
#define CUSTOM_SRVS__SRV__DETAIL__MOVE_ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in srv/MoveOrder in the package custom_srvs.
typedef struct custom_srvs__srv__MoveOrder_Request
{
  geometry_msgs__msg__Pose location;
} custom_srvs__srv__MoveOrder_Request;

// Struct for a sequence of custom_srvs__srv__MoveOrder_Request.
typedef struct custom_srvs__srv__MoveOrder_Request__Sequence
{
  custom_srvs__srv__MoveOrder_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_srvs__srv__MoveOrder_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'ack'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/MoveOrder in the package custom_srvs.
typedef struct custom_srvs__srv__MoveOrder_Response
{
  rosidl_runtime_c__String ack;
} custom_srvs__srv__MoveOrder_Response;

// Struct for a sequence of custom_srvs__srv__MoveOrder_Response.
typedef struct custom_srvs__srv__MoveOrder_Response__Sequence
{
  custom_srvs__srv__MoveOrder_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_srvs__srv__MoveOrder_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_SRVS__SRV__DETAIL__MOVE_ORDER__STRUCT_H_
