cmake_minimum_required(VERSION 2.8.3)
project(rsp_navigation)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  gazebo_msgs
  gazebo_dev
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
  turtlebot3_description
  turtlebot3_gazebo
  rsp_msgs
  gazebo_ros_link_attacher
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES rsp_navigation
#  CATKIN_DEPENDS gazebo_ros geometry_msgs nav_msgs roscpp rospy sensor_msgs std_msgs tf turtlebot3_description turtlebot3_gazebo
#  DEPENDS system_lib
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
 add_library(rsp_navigation
   src/rsp_go_to_point_server.cpp
   src/rsp_go_to_point_client.cpp
 )


add_executable(rsp_velocity_assignment_node src/rsp_velocity_assignment_node.cpp)
add_executable(rsp_reconfiguration_node src/rsp_reconfiguration_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(rsp_velocity_assignment_node
   ${catkin_LIBRARIES}
)

target_link_libraries(rsp_reconfiguration_node
   ${catkin_LIBRARIES}
)


add_executable(rsp_go_to_point_server_node src/rsp_go_to_point_server_node.cpp)
target_link_libraries(rsp_go_to_point_server_node 
  ${catkin_LIBRARIES}
  rsp_navigation
)

add_executable(rsp_go_to_point_client_node src/rsp_go_to_point_client_node.cpp)
target_link_libraries(rsp_go_to_point_client_node 
  ${catkin_LIBRARIES}
  rsp_navigation
)


