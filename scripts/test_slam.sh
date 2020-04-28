#!/bin/sh
xterm  -e  " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot world.launch" &
sleep 5
xterm -e   " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot gmapping.launch" &
sleep 5
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot teleop.launch" &
sleep 5
xterm -e " source /home/robond/catkin_ws/devel/setup.bash; roslaunch my_robot rviz.launch"
