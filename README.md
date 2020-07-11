# Home Service Robot
## Project Write-Up

**Click [here](https://youtu.be/-R4b8nY2FGE) to view a Youtube video of this project.**

This is the final project for my Udacity Robotics Software Engineer program.  It incoroporates all of the topics covered, including creating and communicating between ROS packages, using Rviz and Gazebo, localization, mapping, and navigation.  In this project, the simulated robot travels from a given point on the map to receive an object, and then to another given point on the map to drop off the item.  A marker in Rviz is used to simulate the object.

![Home Service Task](https://github.com/robinlamb/HomeServiceRobot/blob/master/images/home_service_1.png)

The my_robot package contains a robot that I modeled using URDF.  It contains Gazebo references to give the simulation color, and uses Gazebo plugins to simulate the lidar and RGBD sensors as well as differential drive.  The package also contains the simulated house that I modeled in Gazebo with the building editor, and my custom launch files and Rviz configurations.

I created the map used for localization in this project using the [teleop_twist_keyboard](http://wiki.ros.org/teleop_twist_keyboard) and the [slam_gmapping](http://wiki.ros.org/gmapping) ROS packages.  The teleop_twist_keyboard package allows you to control the robot with the computer keyboard.  The slam_gmapping package creates a 2-D map with SLAM using the robot's poses and the lidar.

![SLAM](https://github.com/robinlamb/HomeServiceRobot/blob/master/images/slam.png)

The pick_objects package is a package that I created to have the robot navigate to the pick up location, wait 5 seconds, then navigate to the drop off location.  I have made a class that publishes a topic named "marker_status" in order to communicate with the add_markers package where the marker should be.  The marker has three possible states "Pickup", "Invisible", or "Dropped", which are published at the appropriate times.  The [ROS navigation stack](http://wiki.ros.org/navigation) is used to estimate the robot's pose and the pose of the navigation goal using [amcl](http://wiki.ros.org/amcl) and to plan a path to the goal.  The package communicates with the navigation stack through a MoveBase client to send the goals, and to tell whether the robot has succeeded in reaching the goal position.

The add_markers package is responsible for putting the marker in the correct location.  It has a class which publishes to the topic "visualization_marker", which the marker in Rviz subscribes to and displays the marker properties.  The class also subscribes to the "marker_status" topic which the pick_objects package publishes, and changes the properties of the marker accordingly.

![Home Service Task](https://github.com/robinlamb/HomeServiceRobot/blob/master/images/home_service_2.png)
