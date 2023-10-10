// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_srvs:srv/MoveOrder.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SRVS__SRV__DETAIL__MOVE_ORDER__BUILDER_HPP_
#define CUSTOM_SRVS__SRV__DETAIL__MOVE_ORDER__BUILDER_HPP_

#include "custom_srvs/srv/detail/move_order__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_srvs
{

namespace srv
{

namespace builder
{

class Init_MoveOrder_Request_location
{
public:
  Init_MoveOrder_Request_location()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_srvs::srv::MoveOrder_Request location(::custom_srvs::srv::MoveOrder_Request::_location_type arg)
  {
    msg_.location = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_srvs::srv::MoveOrder_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_srvs::srv::MoveOrder_Request>()
{
  return custom_srvs::srv::builder::Init_MoveOrder_Request_location();
}

}  // namespace custom_srvs


namespace custom_srvs
{

namespace srv
{

namespace builder
{

class Init_MoveOrder_Response_ack
{
public:
  Init_MoveOrder_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_srvs::srv::MoveOrder_Response ack(::custom_srvs::srv::MoveOrder_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_srvs::srv::MoveOrder_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_srvs::srv::MoveOrder_Response>()
{
  return custom_srvs::srv::builder::Init_MoveOrder_Response_ack();
}

}  // namespace custom_srvs

#endif  // CUSTOM_SRVS__SRV__DETAIL__MOVE_ORDER__BUILDER_HPP_
