// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_srvs:srv/MoveOrder.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_srvs/srv/detail/move_order__rosidl_typesupport_introspection_c.h"
#include "custom_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_srvs/srv/detail/move_order__functions.h"
#include "custom_srvs/srv/detail/move_order__struct.h"


// Include directives for member types
// Member `location`
#include "geometry_msgs/msg/pose.h"
// Member `location`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_srvs__srv__MoveOrder_Request__init(message_memory);
}

void MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_fini_function(void * message_memory)
{
  custom_srvs__srv__MoveOrder_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_member_array[1] = {
  {
    "location",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_srvs__srv__MoveOrder_Request, location),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_members = {
  "custom_srvs__srv",  // message namespace
  "MoveOrder_Request",  // message name
  1,  // number of fields
  sizeof(custom_srvs__srv__MoveOrder_Request),
  MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_member_array,  // message members
  MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_type_support_handle = {
  0,
  &MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder_Request)() {
  MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_type_support_handle.typesupport_identifier) {
    MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveOrder_Request__rosidl_typesupport_introspection_c__MoveOrder_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_srvs/srv/detail/move_order__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_srvs/srv/detail/move_order__functions.h"
// already included above
// #include "custom_srvs/srv/detail/move_order__struct.h"


// Include directives for member types
// Member `ack`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_srvs__srv__MoveOrder_Response__init(message_memory);
}

void MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_fini_function(void * message_memory)
{
  custom_srvs__srv__MoveOrder_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_member_array[1] = {
  {
    "ack",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_srvs__srv__MoveOrder_Response, ack),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_members = {
  "custom_srvs__srv",  // message namespace
  "MoveOrder_Response",  // message name
  1,  // number of fields
  sizeof(custom_srvs__srv__MoveOrder_Response),
  MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_member_array,  // message members
  MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_type_support_handle = {
  0,
  &MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder_Response)() {
  if (!MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_type_support_handle.typesupport_identifier) {
    MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveOrder_Response__rosidl_typesupport_introspection_c__MoveOrder_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_srvs/srv/detail/move_order__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_members = {
  "custom_srvs__srv",  // service namespace
  "MoveOrder",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_Request_message_type_support_handle,
  NULL  // response message
  // custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_type_support_handle = {
  0,
  &custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_srvs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder)() {
  if (!custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_type_support_handle.typesupport_identifier) {
    custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_srvs, srv, MoveOrder_Response)()->data;
  }

  return &custom_srvs__srv__detail__move_order__rosidl_typesupport_introspection_c__MoveOrder_service_type_support_handle;
}
