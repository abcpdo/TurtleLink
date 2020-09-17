#include <rsp_navigation/rsp_go_to_point_client.hpp>
#include <ros/ros.h>

move_to_point_client::move_to_point_client(ros::NodeHandle& nh):
	nh(nh) {
	clt = nh.serviceClient<rsp_msgs::Move>("move_to_point");
  ROS_INFO("constructor");
	}

move_to_point_client::~move_to_point_client(){}

bool move_to_point_client::call(rsp_msgs::Move srv) {
  if (clt.call(srv))
  {
    ROS_INFO("success?: %d", srv.response.success);
    return 0;
  }
  else
  {
    ROS_ERROR("Failed to call service move_to_point");
    return 1;
  }
}