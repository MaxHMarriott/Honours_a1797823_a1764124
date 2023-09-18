// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:srv/Policy.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__SRV__DETAIL__POLICY__TRAITS_HPP_
#define CUSTOM_MSGS__SRV__DETAIL__POLICY__TRAITS_HPP_

#include "custom_msgs/srv/detail/policy__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pose'
#include "custom_msgs/msg/detail/pose__traits.hpp"
// Member 'eta'
#include "custom_msgs/msg/detail/float__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::srv::Policy_Request>()
{
  return "custom_msgs::srv::Policy_Request";
}

template<>
inline const char * name<custom_msgs::srv::Policy_Request>()
{
  return "custom_msgs/srv/Policy_Request";
}

template<>
struct has_fixed_size<custom_msgs::srv::Policy_Request>
  : std::integral_constant<bool, has_fixed_size<custom_msgs::msg::Float>::value && has_fixed_size<custom_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<custom_msgs::srv::Policy_Request>
  : std::integral_constant<bool, has_bounded_size<custom_msgs::msg::Float>::value && has_bounded_size<custom_msgs::msg::Pose>::value> {};

template<>
struct is_message<custom_msgs::srv::Policy_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'ack'
#include "custom_msgs/msg/detail/string__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::srv::Policy_Response>()
{
  return "custom_msgs::srv::Policy_Response";
}

template<>
inline const char * name<custom_msgs::srv::Policy_Response>()
{
  return "custom_msgs/srv/Policy_Response";
}

template<>
struct has_fixed_size<custom_msgs::srv::Policy_Response>
  : std::integral_constant<bool, has_fixed_size<custom_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<custom_msgs::srv::Policy_Response>
  : std::integral_constant<bool, has_bounded_size<custom_msgs::msg::String>::value> {};

template<>
struct is_message<custom_msgs::srv::Policy_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::srv::Policy>()
{
  return "custom_msgs::srv::Policy";
}

template<>
inline const char * name<custom_msgs::srv::Policy>()
{
  return "custom_msgs/srv/Policy";
}

template<>
struct has_fixed_size<custom_msgs::srv::Policy>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msgs::srv::Policy_Request>::value &&
    has_fixed_size<custom_msgs::srv::Policy_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msgs::srv::Policy>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msgs::srv::Policy_Request>::value &&
    has_bounded_size<custom_msgs::srv::Policy_Response>::value
  >
{
};

template<>
struct is_service<custom_msgs::srv::Policy>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msgs::srv::Policy_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msgs::srv::Policy_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__SRV__DETAIL__POLICY__TRAITS_HPP_
