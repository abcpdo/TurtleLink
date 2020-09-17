#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <vector>
#include <string>
#include <sstream>




//Initialize variables
ros::NodeHandle *nh;
int robot_count;
int init_robot_count;
double robot_gap;
int robot_configuration;
std::vector<ros::Publisher> publishers;
geometry_msgs::Twist msg_out;




void callback(const geometry_msgs::Twist& msg){

        //Get number of robots
    ros::param::get("/robot_count",robot_count);


        //if the total number of robots has increased add more publishers
    if (robot_count > init_robot_count){
        for(int i = init_robot_count; i < robot_count; i++){
            std::string s;
            std::stringstream out;
            out << i+1;
            s = out.str();
            publishers.push_back(nh->advertise<geometry_msgs::Twist>("/burger_"+s+"/cmd_vel",100));
        }
        init_robot_count = robot_count;
    }


    //Get navigation mode
    ros::param::get("/robot_configuration",robot_configuration);
    
    //Get robot gap space
    ros::param::get("/robot_gap",robot_gap);


    if(robot_configuration != 0){

        for(int i = 0; i < robot_count; i++){

            //calculate i_th robot's twist velocity using math (see notes folder)
            //assuming input is at the center of the line
            msg_out.linear.x = msg.angular.z*((i+1)-((robot_count-1)/2))*robot_gap+msg.linear.x;
            msg_out.angular.z = msg.angular.z; 

            ROS_INFO("publishing to velocities to each robot");
            publishers.at(i).publish(msg_out);
            
        }    
    }   
}

int main(int argc, char** argv){
    //Initialzie node
    ros::init(argc, argv, "velocity_assignment");
    nh = new ros::NodeHandle;
    //Get number of robots
    ros::param::get("/robot_count",init_robot_count);
    ROS_INFO("number of turtles: [%d]",robot_count);

    //create vector of publisher objects
    for(int i = 0; i < init_robot_count; i++){
        std::string s;
        std::stringstream out;
        out << i+1;
        s = out.str();
        publishers.push_back(nh->advertise<geometry_msgs::Twist>("/burger_"+s+"/cmd_vel",100));
    }

    ros::Subscriber sub = nh->subscribe("/cmd_vel",100,&callback);

    ros::spin();

    return 0;   
}