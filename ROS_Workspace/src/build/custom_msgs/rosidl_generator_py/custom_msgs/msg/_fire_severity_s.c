// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_msgs:msg/FireSeverity.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_msgs/msg/detail/fire_severity__struct.h"
#include "custom_msgs/msg/detail/fire_severity__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_msgs__msg__fire_severity__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_msgs.msg._fire_severity.FireSeverity", full_classname_dest, 43) == 0);
  }
  custom_msgs__msg__FireSeverity * ros_message = _ros_message;
  {  // severity
    PyObject * field = PyObject_GetAttrString(_pymsg, "severity");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->severity, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // isdetected
    PyObject * field = PyObject_GetAttrString(_pymsg, "isdetected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->isdetected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // fire_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "fire_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fire_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fire_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "fire_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fire_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_msgs__msg__fire_severity__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FireSeverity */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_msgs.msg._fire_severity");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FireSeverity");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_msgs__msg__FireSeverity * ros_message = (custom_msgs__msg__FireSeverity *)raw_ros_message;
  {  // severity
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->severity.data,
      strlen(ros_message->severity.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "severity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // isdetected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->isdetected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "isdetected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fire_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fire_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fire_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fire_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fire_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fire_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
