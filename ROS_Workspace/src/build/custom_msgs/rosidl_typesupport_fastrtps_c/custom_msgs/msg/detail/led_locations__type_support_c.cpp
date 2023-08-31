// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/LEDLocations.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/led_locations__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/led_locations__struct.h"
#include "custom_msgs/msg/detail/led_locations__functions.h"
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


// forward declare type support functions


using _LEDLocations__ros_msg_type = custom_msgs__msg__LEDLocations;

static bool _LEDLocations__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LEDLocations__ros_msg_type * ros_message = static_cast<const _LEDLocations__ros_msg_type *>(untyped_ros_message);
  // Field name: isled1
  {
    cdr << (ros_message->isled1 ? true : false);
  }

  // Field name: isled2
  {
    cdr << (ros_message->isled2 ? true : false);
  }

  // Field name: led1x
  {
    cdr << ros_message->led1x;
  }

  // Field name: led2x
  {
    cdr << ros_message->led2x;
  }

  // Field name: led1y
  {
    cdr << ros_message->led1y;
  }

  // Field name: led2y
  {
    cdr << ros_message->led2y;
  }

  return true;
}

static bool _LEDLocations__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LEDLocations__ros_msg_type * ros_message = static_cast<_LEDLocations__ros_msg_type *>(untyped_ros_message);
  // Field name: isled1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->isled1 = tmp ? true : false;
  }

  // Field name: isled2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->isled2 = tmp ? true : false;
  }

  // Field name: led1x
  {
    cdr >> ros_message->led1x;
  }

  // Field name: led2x
  {
    cdr >> ros_message->led2x;
  }

  // Field name: led1y
  {
    cdr >> ros_message->led1y;
  }

  // Field name: led2y
  {
    cdr >> ros_message->led2y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__LEDLocations(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LEDLocations__ros_msg_type * ros_message = static_cast<const _LEDLocations__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name isled1
  {
    size_t item_size = sizeof(ros_message->isled1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name isled2
  {
    size_t item_size = sizeof(ros_message->isled2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name led1x
  {
    size_t item_size = sizeof(ros_message->led1x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name led2x
  {
    size_t item_size = sizeof(ros_message->led2x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name led1y
  {
    size_t item_size = sizeof(ros_message->led1y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name led2y
  {
    size_t item_size = sizeof(ros_message->led2y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LEDLocations__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__LEDLocations(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__LEDLocations(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: isled1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: isled2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: led1x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: led2x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: led1y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: led2y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LEDLocations__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_msgs__msg__LEDLocations(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LEDLocations = {
  "custom_msgs::msg",
  "LEDLocations",
  _LEDLocations__cdr_serialize,
  _LEDLocations__cdr_deserialize,
  _LEDLocations__get_serialized_size,
  _LEDLocations__max_serialized_size
};

static rosidl_message_type_support_t _LEDLocations__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LEDLocations,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, LEDLocations)() {
  return &_LEDLocations__type_support;
}

#if defined(__cplusplus)
}
#endif
