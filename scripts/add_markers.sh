#!/bin/sh
xterm  -e  " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot world.launch" &
sleep 5
xterm -e   " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot amcl.launch" &
sleep 7
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot rviz_markers.launch" &
sleep 15
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch add_markers_test add_markers_test.launch"
