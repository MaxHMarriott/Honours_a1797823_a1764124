// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_srvs:srv/Policy.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SRVS__SRV__DETAIL__POLICY__TRAITS_HPP_
#define CUSTOM_SRVS__SRV__DETAIL__POLICY__TRAITS_HPP_

#include "custom_srvs/srv/detail/policy__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_srvs::srv::Policy_Request>()
{
  return "custom_srvs::srv::Policy_Request";
}

template<>
inline const char * name<custom_srvs::srv::Policy_Request>()
{
  return "custom_srvs/srv/Policy_Request";
}

template<>
struct has_fixed_size<custom_srvs::srv::Policy_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<custom_srvs::srv::Policy_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<custom_srvs::srv::Policy_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_srvs::srv::Policy_Response>()
{
  return "custom_srvs::srv::Policy_Response";
}

template<>
inline const char * name<custom_srvs::srv::Policy_Response>()
{
  return "custom_srvs/srv/Policy_Response";
}

template<>
struct has_fixed_size<custom_srvs::srv::Policy_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_srvs::srv::Policy_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_srvs::srv::Policy_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_srvs::srv::Policy>()
{
  return "custom_srvs::srv::Policy";
}

template<>
inline const char * name<custom_srvs::srv::Policy>()
{
  return "custom_srvs/srv/Policy";
}

template<>
struct has_fixed_size<custom_srvs::srv::Policy>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_srvs::srv::Policy_Request>::value &&
    has_fixed_size<custom_srvs::srv::Policy_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_srvs::srv::Policy>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_srvs::srv::Policy_Request>::value &&
    has_bounded_size<custom_srvs::srv::Policy_Response>::value
  >
{
};

template<>
struct is_service<custom_srvs::srv::Policy>
  : std::true_type
{
};

template<>
struct is_service_request<custom_srvs::srv::Policy_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_srvs::srv::Policy_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_SRVS__SRV__DETAIL__POLICY__TRAITS_HPP_
