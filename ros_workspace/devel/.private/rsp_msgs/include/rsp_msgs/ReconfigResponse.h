// Generated by gencpp from file rsp_msgs/ReconfigResponse.msg
// DO NOT EDIT!


#ifndef RSP_MSGS_MESSAGE_RECONFIGRESPONSE_H
#define RSP_MSGS_MESSAGE_RECONFIGRESPONSE_H


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
struct ReconfigResponse_
{
  typedef ReconfigResponse_<ContainerAllocator> Type;

  ReconfigResponse_()
    : success(false)  {
    }
  ReconfigResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ReconfigResponse_

typedef ::rsp_msgs::ReconfigResponse_<std::allocator<void> > ReconfigResponse;

typedef boost::shared_ptr< ::rsp_msgs::ReconfigResponse > ReconfigResponsePtr;
typedef boost::shared_ptr< ::rsp_msgs::ReconfigResponse const> ReconfigResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rsp_msgs::ReconfigResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::rsp_msgs::ReconfigResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rsp_msgs/ReconfigResponse";
  }

  static const char* value(const ::rsp_msgs::ReconfigResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
\n\
";
  }

  static const char* value(const ::rsp_msgs::ReconfigResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReconfigResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rsp_msgs::ReconfigResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rsp_msgs::ReconfigResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RSP_MSGS_MESSAGE_RECONFIGRESPONSE_H
