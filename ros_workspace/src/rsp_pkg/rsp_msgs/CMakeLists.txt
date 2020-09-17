cmake_minimum_required(VERSION 2.8.3)
project(rsp_msgs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(
   FILES
   Message.msg
)

add_service_files(
  FILES
  Reconfig.srv
  Move.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES assignment1_msgs
   CATKIN_DEPENDS roscpp std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
   include
  ${catkin_INCLUDE_DIRS}
)
