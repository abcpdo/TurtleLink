cmake_minimum_required(VERSION 2.8.3)
project(rsp_rviz)

add_compile_options(-std=c++11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(catkin REQUIRED COMPONENTS
  rviz
  geometry_msgs
  rsp_msgs
)

find_package(Qt5 ${rviz_QT_VERSION} EXACT REQUIRED Core Widgets)

catkin_package(
   INCLUDE_DIRS include
#  LIBRARIES robotiq_3f_rviz
#  CATKIN_DEPENDS robotiq_s_model_articulated_msgs rviz
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# rsp_rviz plugin
add_library(rsp_rviz src/rsp_rviz.cpp)
target_link_libraries(rsp_rviz ${catkin_LIBRARIES} Qt5::Widgets)

# rsp_command node
add_executable(rsp_command_node src/rsp_command_node.cpp)
target_link_libraries(rsp_command_node ${catkin_LIBRARIES} rsp_rviz)

#############
## Install ##
#############

install(TARGETS rsp_rviz
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES
  plugin_description.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY icons/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/icons)

#############
## Testing ##
#############
