// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/fire_severity__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/fire_severity__struct.h"
#include "custom_msgs/msg/detail/fire_severity__functions.h"
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

#include "rosidl_runtime_c/string.h"  // severity
#include "rosidl_runtime_c/string_functions.h"  // severity

// forward declare type support functions


using _FireSeverity__ros_msg_type = custom_msgs__msg__FireSeverity;

static bool _FireSeverity__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FireSeverity__ros_msg_type * ros_message = static_cast<const _FireSeverity__ros_msg_type *>(untyped_ros_message);
  // Field name: severity
  {
    const rosidl_runtime_c__String * str = &ros_message->severity;
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

  // Field name: isdetected
  {
    cdr << (ros_message->isdetected ? true : false);
  }

  // Field name: fire_x
  {
    cdr << ros_message->fire_x;
  }

  // Field name: fire_y
  {
    cdr << ros_message->fire_y;
  }

  return true;
}

static bool _FireSeverity__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FireSeverity__ros_msg_type * ros_message = static_cast<_FireSeverity__ros_msg_type *>(untyped_ros_message);
  // Field name: severity
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->severity.data) {
      rosidl_runtime_c__String__init(&ros_message->severity);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->severity,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'severity'\n");
      return false;
    }
  }

  // Field name: isdetected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->isdetected = tmp ? true : false;
  }

  // Field name: fire_x
  {
    cdr >> ros_message->fire_x;
  }

  // Field name: fire_y
  {
    cdr >> ros_message->fire_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__FireSeverity(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FireSeverity__ros_msg_type * ros_message = static_cast<const _FireSeverity__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name severity
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->severity.size + 1);
  // field.name isdetected
  {
    size_t item_size = sizeof(ros_message->isdetected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fire_x
  {
    size_t item_size = sizeof(ros_message->fire_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fire_y
  {
    size_t item_size = sizeof(ros_message->fire_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FireSeverity__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__FireSeverity(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__FireSeverity(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: severity
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: isdetected
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fire_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: fire_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _FireSeverity__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_msgs__msg__FireSeverity(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_FireSeverity = {
  "custom_msgs::msg",
  "FireSeverity",
  _FireSeverity__cdr_serialize,
  _FireSeverity__cdr_deserialize,
  _FireSeverity__get_serialized_size,
  _FireSeverity__max_serialized_size
};

static rosidl_message_type_support_t _FireSeverity__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FireSeverity,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, FireSeverity)() {
  return &_FireSeverity__type_support;
}

#if defined(__cplusplus)
}
#endif
