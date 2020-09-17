cmake_minimum_required(VERSION 2.8.3)
project(rsp_usercontrol)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
  turtlebot3_description
  turtlebot3_gazebo
)



## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

find_package(gazebo REQUIRED)
catkin_python_setup()

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS gazebo_ros geometry_msgs nav_msgs roscpp rospy sensor_msgs std_msgs tf turtlebot3_description turtlebot3_gazebo
  LIBRARIES ${PROJECT_NAME}
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} src/rsp_teleop_joy.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

add_executable(rsp_teleop_joy_node src/rsp_teleop_joy_node.cpp)
target_link_libraries(rsp_teleop_joy_node ${PROJECT_NAME} ${catkin_LIBRARIES})

#############
## Install ##
#############

catkin_install_python(PROGRAMS
  nodes/rsp_teleop_key
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

#############
## Testing ##
#############



