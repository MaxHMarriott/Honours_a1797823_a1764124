// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_srvs:srv/Policy.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_srvs/srv/detail/policy__rosidl_typesupport_introspection_c.h"
#include "custom_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_srvs/srv/detail/policy__functions.h"
#include "custom_srvs/srv/detail/policy__struct.h"


// Include directives for member types
// Member `location`
#include "geometry_msgs/msg/pose.h"
// Member `location`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_srvs__srv__Policy_Request__init(message_memory);
}

void Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_fini_function(void * message_memory)
{
  custom_srvs__srv__Policy_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_member_array[2] = {
  {
    "location",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_srvs__srv__Policy_Request, location),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_srvs__srv__Policy_Request, eta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_members = {
  "custom_srvs__srv",  // message namespace
  "Policy_Request",  // message name
  2,  // number of fields
  sizeof(custom_srvs__srv__Policy_Request),
  Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_member_array,  // message members
  Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_type_support_handle = {
  0,
  &Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy_Request)() {
  Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_type_support_handle.typesupport_identifier) {
    Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Policy_Request__rosidl_typesupport_introspection_c__Policy_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_srvs/srv/detail/policy__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_srvs/srv/detail/policy__functions.h"
// already included above
// #include "custom_srvs/srv/detail/policy__struct.h"


// Include directives for member types
// Member `ack`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_srvs__srv__Policy_Response__init(message_memory);
}

void Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_fini_function(void * message_memory)
{
  custom_srvs__srv__Policy_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_member_array[1] = {
  {
    "ack",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_srvs__srv__Policy_Response, ack),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_members = {
  "custom_srvs__srv",  // message namespace
  "Policy_Response",  // message name
  1,  // number of fields
  sizeof(custom_srvs__srv__Policy_Response),
  Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_member_array,  // message members
  Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_type_support_handle = {
  0,
  &Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy_Response)() {
  if (!Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_type_support_handle.typesupport_identifier) {
    Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Policy_Response__rosidl_typesupport_introspection_c__Policy_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_srvs/srv/detail/policy__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_members = {
  "custom_srvs__srv",  // service namespace
  "Policy",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_Request_message_type_support_handle,
  NULL  // response message
  // custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_type_support_handle = {
  0,
  &custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_srvs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy)() {
  if (!custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_type_support_handle.typesupport_identifier) {
    custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, Policy_Response)()->data;
  }

  return &custom_srvs__srv__detail__policy__rosidl_typesupport_introspection_c__Policy_service_type_support_handle;
}
