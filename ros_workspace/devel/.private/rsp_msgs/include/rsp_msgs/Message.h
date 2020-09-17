// Generated by gencpp from file rsp_msgs/Message.msg
// DO NOT EDIT!


#ifndef RSP_MSGS_MESSAGE_MESSAGE_H
#define RSP_MSGS_MESSAGE_MESSAGE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rsp_msgs
{
template <class ContainerAllocator>
struct Message_
{
  typedef Message_<ContainerAllocator> Type;

  Message_()
    : q0(0)
    , q1(0)
    , q2(0)
    , q3(0)  {
    }
  Message_(const ContainerAllocator& _alloc)
    : q0(0)
    , q1(0)
    , q2(0)
    , q3(0)  {
  (void)_alloc;
    }



   typedef uint32_t _q0_type;
  _q0_type q0;

   typedef uint32_t _q1_type;
  _q1_type q1;

   typedef uint32_t _q2_type;
  _q2_type q2;

   typedef uint32_t _q3_type;
  _q3_type q3;





  typedef boost::shared_ptr< ::rsp_msgs::Message_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rsp_msgs::Message_<ContainerAllocator> const> ConstPtr;

}; // struct Message_

typedef ::rsp_msgs::Message_<std::allocator<void> > Message;

typedef boost::shared_ptr< ::rsp_msgs::Message > MessagePtr;
typedef boost::shared_ptr< ::rsp_msgs::Message const> MessageConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rsp_msgs::Message_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rsp_msgs::Message_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rsp_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'rsp_msgs': ['/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rsp_msgs::Message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rsp_msgs::Message_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rsp_msgs::Message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rsp_msgs::Message_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rsp_msgs::Message_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rsp_msgs::Message_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rsp_msgs::Message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ff38cde609e9b3b19927a6880a3e6ba";
  }

  static const char* value(const ::rsp_msgs::Message_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ff38cde609e9b3bULL;
  static const uint64_t static_value2 = 0x19927a6880a3e6baULL;
};

template<class ContainerAllocator>
struct DataType< ::rsp_msgs::Message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rsp_msgs/Message";
  }

  static const char* value(const ::rsp_msgs::Message_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rsp_msgs::Message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 q0\n\
uint32 q1\n\
uint32 q2\n\
uint32 q3\n\
";
  }

  static const char* value(const ::rsp_msgs::Message_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rsp_msgs::Message_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.q0);
      stream.next(m.q1);
      stream.next(m.q2);
      stream.next(m.q3);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Message_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rsp_msgs::Message_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rsp_msgs::Message_<ContainerAllocator>& v)
  {
    s << indent << "q0: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.q0);
    s << indent << "q1: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.q1);
    s << indent << "q2: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.q2);
    s << indent << "q3: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.q3);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RSP_MSGS_MESSAGE_MESSAGE_H