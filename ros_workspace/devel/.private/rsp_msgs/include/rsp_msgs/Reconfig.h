// Generated by gencpp from file rsp_msgs/Reconfig.msg
// DO NOT EDIT!


#ifndef RSP_MSGS_MESSAGE_RECONFIG_H
#define RSP_MSGS_MESSAGE_RECONFIG_H

#include <ros/service_traits.h>


#include <rsp_msgs/ReconfigRequest.h>
#include <rsp_msgs/ReconfigResponse.h>


namespace rsp_msgs
{

struct Reconfig
{

typedef ReconfigRequest Request;
typedef ReconfigResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Reconfig
} // namespace rsp_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rsp_msgs::Reconfig > {
  static const char* value()
  {
    return "fd27df16901bf0767f619a2a1147b980";
  }

  static const char* value(const ::rsp_msgs::Reconfig&) { return value(); }
};

template<>
struct DataType< ::rsp_msgs::Reconfig > {
  static const char* value()
  {
    return "rsp_msgs/Reconfig";
  }

  static const char* value(const ::rsp_msgs::Reconfig&) { return value(); }
};


// service_traits::MD5Sum< ::rsp_msgs::ReconfigRequest> should match 
// service_traits::MD5Sum< ::rsp_msgs::Reconfig > 
template<>
struct MD5Sum< ::rsp_msgs::ReconfigRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rsp_msgs::Reconfig >::value();
  }
  static const char* value(const ::rsp_msgs::ReconfigRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rsp_msgs::ReconfigRequest> should match 
// service_traits::DataType< ::rsp_msgs::Reconfig > 
template<>
struct DataType< ::rsp_msgs::ReconfigRequest>
{
  static const char* value()
  {
    return DataType< ::rsp_msgs::Reconfig >::value();
  }
  static const char* value(const ::rsp_msgs::ReconfigRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rsp_msgs::ReconfigResponse> should match 
// service_traits::MD5Sum< ::rsp_msgs::Reconfig > 
template<>
struct MD5Sum< ::rsp_msgs::ReconfigResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rsp_msgs::Reconfig >::value();
  }
  static const char* value(const ::rsp_msgs::ReconfigResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rsp_msgs::ReconfigResponse> should match 
// service_traits::DataType< ::rsp_msgs::Reconfig > 
template<>
struct DataType< ::rsp_msgs::ReconfigResponse>
{
  static const char* value()
  {
    return DataType< ::rsp_msgs::Reconfig >::value();
  }
  static const char* value(const ::rsp_msgs::ReconfigResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // RSP_MSGS_MESSAGE_RECONFIG_H