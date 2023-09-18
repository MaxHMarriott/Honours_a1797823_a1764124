# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_srvs:srv/Policy.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Policy_Request(type):
    """Metaclass of message 'Policy_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_srvs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_srvs.srv.Policy_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__policy__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__policy__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__policy__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__policy__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__policy__request

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Policy_Request(metaclass=Metaclass_Policy_Request):
    """Message class 'Policy_Request'."""

    __slots__ = [
        '_location',
        '_eta',
    ]

    _fields_and_field_types = {
        'location': 'geometry_msgs/Point',
        'eta': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.location = kwargs.get('location', Point())
        self.eta = kwargs.get('eta', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.location != other.location:
            return False
        if self.eta != other.eta:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def location(self):
        """Message field 'location'."""
        return self._location

    @location.setter
    def location(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'location' field must be a sub message of type 'Point'"
        self._location = value

    @property
    def eta(self):
        """Message field 'eta'."""
        return self._eta

    @eta.setter
    def eta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'eta' field must be of type 'float'"
        self._eta = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_Policy_Response(type):
    """Metaclass of message 'Policy_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_srvs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_srvs.srv.Policy_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__policy__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__policy__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__policy__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__policy__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__policy__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Policy_Response(metaclass=Metaclass_Policy_Response):
    """Message class 'Policy_Response'."""

    __slots__ = [
        '_ack',
    ]

    _fields_and_field_types = {
        'ack': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ack = kwargs.get('ack', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.ack != other.ack:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def ack(self):
        """Message field 'ack'."""
        return self._ack

    @ack.setter
    def ack(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ack' field must be of type 'str'"
        self._ack = value


class Metaclass_Policy(type):
    """Metaclass of service 'Policy'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_srvs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_srvs.srv.Policy')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__policy

            from custom_srvs.srv import _policy
            if _policy.Metaclass_Policy_Request._TYPE_SUPPORT is None:
                _policy.Metaclass_Policy_Request.__import_type_support__()
            if _policy.Metaclass_Policy_Response._TYPE_SUPPORT is None:
                _policy.Metaclass_Policy_Response.__import_type_support__()


class Policy(metaclass=Metaclass_Policy):
    from custom_srvs.srv._policy import Policy_Request as Request
    from custom_srvs.srv._policy import Policy_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
