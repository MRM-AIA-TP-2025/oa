// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from sensors:msg/NavigationData.idl
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
#include "sensors/msg/detail/navigation_data__struct.h"
#include "sensors/msg/detail/navigation_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool sensors__msg__navigation_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("sensors.msg._navigation_data.NavigationData", full_classname_dest, 43) == 0);
  }
  sensors__msg__NavigationData * ros_message = _ros_message;
  {  // distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bearing
    PyObject * field = PyObject_GetAttrString(_pymsg, "bearing");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bearing = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // isonline
    PyObject * field = PyObject_GetAttrString(_pymsg, "isonline");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->isonline = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * sensors__msg__navigation_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavigationData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("sensors.msg._navigation_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavigationData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  sensors__msg__NavigationData * ros_message = (sensors__msg__NavigationData *)raw_ros_message;
  {  // distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bearing
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bearing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bearing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // isonline
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->isonline ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "isonline", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
