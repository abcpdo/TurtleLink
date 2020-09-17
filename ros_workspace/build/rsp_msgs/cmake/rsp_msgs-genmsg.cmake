# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rsp_msgs: 1 messages, 2 services")

set(MSG_I_FLAGS "-Irsp_msgs:/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rsp_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" NAME_WE)
add_custom_target(_rsp_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rsp_msgs" "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" ""
)

get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" NAME_WE)
add_custom_target(_rsp_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rsp_msgs" "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" ""
)

get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" NAME_WE)
add_custom_target(_rsp_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rsp_msgs" "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rsp_msgs
)

### Generating Services
_generate_srv_cpp(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rsp_msgs
)
_generate_srv_cpp(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rsp_msgs
)

### Generating Module File
_generate_module_cpp(rsp_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rsp_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rsp_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rsp_msgs_generate_messages rsp_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_cpp _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_cpp _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_cpp _rsp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rsp_msgs_gencpp)
add_dependencies(rsp_msgs_gencpp rsp_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rsp_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rsp_msgs
)

### Generating Services
_generate_srv_eus(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rsp_msgs
)
_generate_srv_eus(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rsp_msgs
)

### Generating Module File
_generate_module_eus(rsp_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rsp_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(rsp_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(rsp_msgs_generate_messages rsp_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_eus _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_eus _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_eus _rsp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rsp_msgs_geneus)
add_dependencies(rsp_msgs_geneus rsp_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rsp_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rsp_msgs
)

### Generating Services
_generate_srv_lisp(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rsp_msgs
)
_generate_srv_lisp(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rsp_msgs
)

### Generating Module File
_generate_module_lisp(rsp_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rsp_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rsp_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(rsp_msgs_generate_messages rsp_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_lisp _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_lisp _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_lisp _rsp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rsp_msgs_genlisp)
add_dependencies(rsp_msgs_genlisp rsp_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rsp_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rsp_msgs
)

### Generating Services
_generate_srv_nodejs(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rsp_msgs
)
_generate_srv_nodejs(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rsp_msgs
)

### Generating Module File
_generate_module_nodejs(rsp_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rsp_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(rsp_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(rsp_msgs_generate_messages rsp_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_nodejs _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_nodejs _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_nodejs _rsp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rsp_msgs_gennodejs)
add_dependencies(rsp_msgs_gennodejs rsp_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rsp_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs
)

### Generating Services
_generate_srv_py(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs
)
_generate_srv_py(rsp_msgs
  "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs
)

### Generating Module File
_generate_module_py(rsp_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rsp_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rsp_msgs_generate_messages rsp_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Move.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_py _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/msg/Message.msg" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_py _rsp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/rsp_pkg/rsp_msgs/srv/Reconfig.srv" NAME_WE)
add_dependencies(rsp_msgs_generate_messages_py _rsp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rsp_msgs_genpy)
add_dependencies(rsp_msgs_genpy rsp_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rsp_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rsp_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rsp_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(rsp_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rsp_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rsp_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(rsp_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rsp_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rsp_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(rsp_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rsp_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rsp_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(rsp_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rsp_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(rsp_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
