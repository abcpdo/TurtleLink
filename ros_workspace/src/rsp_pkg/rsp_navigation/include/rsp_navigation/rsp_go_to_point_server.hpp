#include <ros/ros.h>
// #include <assignment1_msgs/SubtractTwoInts.h>
#include <rsp_msgs/Move.h>

class move_to_point_server {
private:
	ros::NodeHandle nh;
	ros::ServiceServer srv;

public:
	move_to_point_server(ros::NodeHandle& nh);
	~move_to_point_server();

};

bool move_to_point(rsp_msgs::Move::Request &req,
         rsp_msgs::Move::Response &res);