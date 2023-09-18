// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_srvs:srv/Policy.idl
// generated code does not contain a copyright notice
#include "custom_srvs/srv/detail/policy__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_srvs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_srvs/srv/detail/policy__struct.h"
#include "custom_srvs/srv/detail/policy__functions.h"
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

#include "geometry_msgs/msg/detail/point__functions.h"  // location

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_srvs
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_srvs
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_srvs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();


using _Policy_Request__ros_msg_type = custom_srvs__srv__Policy_Request;

static bool _Policy_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Policy_Request__ros_msg_type * ros_message = static_cast<const _Policy_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: location
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->location, cdr))
    {
      return false;
    }
  }

  // Field name: eta
  {
    cdr << ros_message->eta;
  }

  return true;
}

static bool _Policy_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Policy_Request__ros_msg_type * ros_message = static_cast<_Policy_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: location
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->location))
    {
      return false;
    }
  }

  // Field name: eta
  {
    cdr >> ros_message->eta;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t get_serialized_size_custom_srvs__srv__Policy_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Policy_Request__ros_msg_type * ros_message = static_cast<const _Policy_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name location

  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->location), current_alignment);
  // field.name eta
  {
    size_t item_size = sizeof(ros_message->eta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Policy_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_srvs__srv__Policy_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t max_serialized_size_custom_srvs__srv__Policy_Request(
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
        max_serialized_size_geometry_msgs__msg__Point(
        full_bounded, current_alignment);
    }
  }
  // member: eta
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Policy_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_srvs__srv__Policy_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Policy_Request = {
  "custom_srvs::srv",
  "Policy_Request",
  _Policy_Request__cdr_serialize,
  _Policy_Request__cdr_deserialize,
  _Policy_Request__get_serialized_size,
  _Policy_Request__max_serialized_size
};

static rosidl_message_type_support_t _Policy_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Policy_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, Policy_Request)() {
  return &_Policy_Request__type_support;
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
// #include "custom_srvs/srv/detail/policy__struct.h"
// already included above
// #include "custom_srvs/srv/detail/policy__functions.h"
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


using _Policy_Response__ros_msg_type = custom_srvs__srv__Policy_Response;

static bool _Policy_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Policy_Response__ros_msg_type * ros_message = static_cast<const _Policy_Response__ros_msg_type *>(untyped_ros_message);
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

static bool _Policy_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Policy_Response__ros_msg_type * ros_message = static_cast<_Policy_Response__ros_msg_type *>(untyped_ros_message);
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
size_t get_serialized_size_custom_srvs__srv__Policy_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Policy_Response__ros_msg_type * ros_message = static_cast<const _Policy_Response__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _Policy_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_srvs__srv__Policy_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_srvs
size_t max_serialized_size_custom_srvs__srv__Policy_Response(
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

static size_t _Policy_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_srvs__srv__Policy_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Policy_Response = {
  "custom_srvs::srv",
  "Policy_Response",
  _Policy_Response__cdr_serialize,
  _Policy_Response__cdr_deserialize,
  _Policy_Response__get_serialized_size,
  _Policy_Response__max_serialized_size
};

static rosidl_message_type_support_t _Policy_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Policy_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, Policy_Response)() {
  return &_Policy_Response__type_support;
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
#include "custom_srvs/srv/policy.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Policy__callbacks = {
  "custom_srvs::srv",
  "Policy",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, Policy_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, Policy_Response)(),
};

static rosidl_service_type_support_t Policy__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Policy__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_srvs, srv, Policy)() {
  return &Policy__handle;
}

#if defined(__cplusplus)
}
#endif
