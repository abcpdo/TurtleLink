#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/turtlebot3_pkgs/turtlebot3_example"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/install/lib/python2.7/dist-packages:/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/build/turtlebot3_example/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/build/turtlebot3_example" \
    "/usr/bin/python2" \
    "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/src/turtlebot3_pkgs/turtlebot3_example/setup.py" \
    build --build-base "/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/build/turtlebot3_example" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/install" --install-scripts="/home/kaiyu/Dropbox/College/Grad/RSP/git_repos/530_707_independent_project/ros_workspace/install/bin"
