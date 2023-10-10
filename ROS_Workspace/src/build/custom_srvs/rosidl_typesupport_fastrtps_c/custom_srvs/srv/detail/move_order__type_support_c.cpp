// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_srvs:srv/MoveOrder.idl
// generated code does not contain a copyright notice
#include "custom_srvs/srv/detail/move_order__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_srvs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_srvs/srv/detail/move_order__struct.h"
#include "custom_srvs/srv/detail/move_order__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose__functions.h"  // location

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_srvs
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_srvs
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_srvs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();


using _MoveOrder_Request__ros_msg_type = custom_srvs__srv__MoveOrder_Request;

static bool _MoveOrder_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MoveOrder_Request__ros_msg_type * ros_message = static_cast<const _MoveOrder_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: location
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->location, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _MoveOrder_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MoveOrder_Request__ros_msg_type * ros_message = static_cast<_MoveOrder_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: location
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->location))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t get_serialized_size_custom_srvs__srv__MoveOrder_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MoveOrder_Request__ros_msg_type * ros_message = static_cast<const _MoveOrder_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name location

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->location), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _MoveOrder_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_srvs__srv__MoveOrder_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t max_serialized_size_custom_srvs__srv__MoveOrder_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: location
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Pose(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MoveOrder_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_srvs__srv__MoveOrder_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MoveOrder_Request = {
  "custom_srvs::srv",
  "MoveOrder_Request",
  _MoveOrder_Request__cdr_serialize,
  _MoveOrder_Request__cdr_deserialize,
  _MoveOrder_Request__get_serialized_size,
  _MoveOrder_Request__max_serialized_size
};

static rosidl_message_type_support_t _MoveOrder_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MoveOrder_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, MoveOrder_Request)() {
  return &_MoveOrder_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "custom_srvs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "custom_srvs/srv/detail/move_order__struct.h"
// already included above
// #include "custom_srvs/srv/detail/move_order__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // ack
#include "rosidl_runtime_c/string_functions.h"  // ack

// forward declare type support functions


using _MoveOrder_Response__ros_msg_type = custom_srvs__srv__MoveOrder_Response;

static bool _MoveOrder_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MoveOrder_Response__ros_msg_type * ros_message = static_cast<const _MoveOrder_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: ack
  {
    const rosidl_runtime_c__String * str = &ros_message->ack;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _MoveOrder_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MoveOrder_Response__ros_msg_type * ros_message = static_cast<_MoveOrder_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: ack
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ack.data) {
      rosidl_runtime_c__String__init(&ros_message->ack);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ack,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ack'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t get_serialized_size_custom_srvs__srv__MoveOrder_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MoveOrder_Response__ros_msg_type * ros_message = static_cast<const _MoveOrder_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ack
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ack.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _MoveOrder_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_srvs__srv__MoveOrder_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t max_serialized_size_custom_srvs__srv__MoveOrder_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: ack
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MoveOrder_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_srvs__srv__MoveOrder_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MoveOrder_Response = {
  "custom_srvs::srv",
  "MoveOrder_Response",
  _MoveOrder_Response__cdr_serialize,
  _MoveOrder_Response__cdr_deserialize,
  _MoveOrder_Response__get_serialized_size,
  _MoveOrder_Response__max_serialized_size
};

static rosidl_message_type_support_t _MoveOrder_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MoveOrder_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, MoveOrder_Response)() {
  return &_MoveOrder_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "custom_srvs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_srvs/srv/move_order.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MoveOrder__callbacks = {
  "custom_srvs::srv",
  "MoveOrder",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, MoveOrder_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, MoveOrder_Response)(),
};

static rosidl_service_type_support_t MoveOrder__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MoveOrder__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, MoveOrder)() {
  return &MoveOrder__handle;
}

#if defined(__cplusplus)
}
#endif
