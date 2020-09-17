execute_process(COMMAND "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/build/rsp_usercontrol/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/build/rsp_usercontrol/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
