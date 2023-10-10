// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_srvs:srv/Policy.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SRVS__SRV__DETAIL__POLICY__BUILDER_HPP_
#define CUSTOM_SRVS__SRV__DETAIL__POLICY__BUILDER_HPP_

#include "custom_srvs/srv/detail/policy__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_srvs
{

namespace srv
{

namespace builder
{

class Init_Policy_Request_eta
{
public:
  explicit Init_Policy_Request_eta(::custom_srvs::srv::Policy_Request & msg)
  : msg_(msg)
  {}
  ::custom_srvs::srv::Policy_Request eta(::custom_srvs::srv::Policy_Request::_eta_type arg)
  {
    msg_.eta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_srvs::srv::Policy_Request msg_;
};

class Init_Policy_Request_location
{
public:
  Init_Policy_Request_location()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Policy_Request_eta location(::custom_srvs::srv::Policy_Request::_location_type arg)
  {
    msg_.location = std::move(arg);
    return Init_Policy_Request_eta(msg_);
  }

private:
  ::custom_srvs::srv::Policy_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_srvs::srv::Policy_Request>()
{
  return custom_srvs::srv::builder::Init_Policy_Request_location();
}

}  // namespace custom_srvs


namespace custom_srvs
{

namespace srv
{

namespace builder
{

class Init_Policy_Response_ack
{
public:
  Init_Policy_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_srvs::srv::Policy_Response ack(::custom_srvs::srv::Policy_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_srvs::srv::Policy_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_srvs::srv::Policy_Response>()
{
  return custom_srvs::srv::builder::Init_Policy_Response_ack();
}

}  // namespace custom_srvs

#endif  // CUSTOM_SRVS__SRV__DETAIL__POLICY__BUILDER_HPP_
