// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_srvs:srv/Policy.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SRVS__SRV__DETAIL__POLICY__STRUCT_HPP_
#define CUSTOM_SRVS__SRV__DETAIL__POLICY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_srvs__srv__Policy_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_srvs__srv__Policy_Request __declspec(deprecated)
#endif

namespace custom_srvs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Policy_Request_
{
  using Type = Policy_Request_<ContainerAllocator>;

  explicit Policy_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->eta = 0.0;
    }
  }

  explicit Policy_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->eta = 0.0;
    }
  }

  // field types and members
  using _location_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _location_type location;
  using _eta_type =
    double;
  _eta_type eta;

  // setters for named parameter idiom
  Type & set__location(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->location = _arg;
    return *this;
  }
  Type & set__eta(
    const double & _arg)
  {
    this->eta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_srvs::srv::Policy_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_srvs::srv::Policy_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_srvs::srv::Policy_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_srvs::srv::Policy_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_srvs__srv__Policy_Request
    std::shared_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_srvs__srv__Policy_Request
    std::shared_ptr<custom_srvs::srv::Policy_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Policy_Request_ & other) const
  {
    if (this->location != other.location) {
      return false;
    }
    if (this->eta != other.eta) {
      return false;
    }
    return true;
  }
  bool operator!=(const Policy_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Policy_Request_

// alias to use template instance with default allocator
using Policy_Request =
  custom_srvs::srv::Policy_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_srvs


#ifndef _WIN32
# define DEPRECATED__custom_srvs__srv__Policy_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_srvs__srv__Policy_Response __declspec(deprecated)
#endif

namespace custom_srvs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Policy_Response_
{
  using Type = Policy_Response_<ContainerAllocator>;

  explicit Policy_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = "";
    }
  }

  explicit Policy_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ack(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = "";
    }
  }

  // field types and members
  using _ack_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _ack_type ack;

  // setters for named parameter idiom
  Type & set__ack(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->ack = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_srvs::srv::Policy_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_srvs::srv::Policy_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_srvs::srv::Policy_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_srvs::srv::Policy_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_srvs__srv__Policy_Response
    std::shared_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_srvs__srv__Policy_Response
    std::shared_ptr<custom_srvs::srv::Policy_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Policy_Response_ & other) const
  {
    if (this->ack != other.ack) {
      return false;
    }
    return true;
  }
  bool operator!=(const Policy_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Policy_Response_

// alias to use template instance with default allocator
using Policy_Response =
  custom_srvs::srv::Policy_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_srvs

namespace custom_srvs
{

namespace srv
{

struct Policy
{
  using Request = custom_srvs::srv::Policy_Request;
  using Response = custom_srvs::srv::Policy_Response;
};

}  // namespace srv

}  // namespace custom_srvs

#endif  // CUSTOM_SRVS__SRV__DETAIL__POLICY__STRUCT_HPP_
