#include <ros/ros.h>
#include <cstdlib>
#include <rsp_navigation/rsp_go_to_point_client.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_to_point_client");
  if (argc != 5)
  {
    ROS_INFO("usage: client_node name X Y theta");
    return 1;
  }

  ros::NodeHandle nh;

  // move_to_point_client client(nh);
  ros::ServiceClient client = nh.serviceClient<rsp_msgs::Move>("move_to_point");

  rsp_msgs::Move srv;


  srv.request.name = atoll(argv[1]);
  srv.request.x = atoll(argv[2]);
  srv.request.y = atoll(argv[3]);
  srv.request.theta = atoll(argv[4]);

  // return client.call(srv);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.success);
  }
  else
  {
    // ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
  return 0;
}

// #include "ros/ros.h"
// #include "rsp_msgs/Move.h"
// #include <cstdlib>

// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "add_two_ints_client");
//   if (argc != 3)
//   {
//     ROS_INFO("usage: add_two_ints_client X Y");
//     return 1;
//   }

//   ros::NodeHandle n;
//   ros::ServiceClient client = n.serviceClient<rsp_msgs::Move>("add_two_ints");
//   rsp_msgs::Move srv;
//   srv.request.x = atoll(argv[1]);
//   srv.request.y = atoll(argv[2]);
//   if (client.call(srv))
//   {
//     ROS_INFO("Sum: %ld", (long int)srv.response.success);
//   }
//   else
//   {
//     ROS_ERROR("Failed to call service add_two_ints");
//     return 1;
//   }

//   return 0;
// }