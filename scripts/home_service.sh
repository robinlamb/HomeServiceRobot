#!/bin/sh
xterm  -e  " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot world.launch" &
sleep 5
xterm -e   " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot amcl.launch" &
sleep 7
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot rviz_markers.launch" &
sleep 20
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch add_markers add_markers.launch" &
sleep 5
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; rostopic echo /marker_status" &
sleep 5
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch pick_objects pick_objects.launch"

