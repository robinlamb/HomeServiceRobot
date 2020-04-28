#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

class AddMarkers {
public:

  visualization_msgs::Marker marker;

  AddMarkers()
      {
         //Publisher
         pub_ = n_.advertise<visualization_msgs::Marker>("visualization_marker", 1);
	   
         marker.header.frame_id = "map";
         marker.header.stamp = ros::Time::now();

         // Set the namespace and id for this marker.
         marker.ns = "add_markers";
         marker.id = 0;

         // Set the marker type to cylinder
         marker.type = visualization_msgs::Marker::CYLINDER;

         // Add the marker
         marker.action = visualization_msgs::Marker::ADD;
         marker.pose.orientation.x = 0.0;
         marker.pose.orientation.y = 0.0;
         marker.pose.orientation.z = 0.0;
         marker.pose.orientation.w = 1.0;

         // Set the scale of the marker
         marker.scale.x = 0.1;
         marker.scale.y = 0.1;
         marker.scale.z = 0.15;

         // Set the color
         marker.color.r = 0.0f;
         marker.color.g = 1.0f;
         marker.color.b = 0.0f;
         marker.color.a = 1.0;

         marker.lifetime = ros::Duration();
	}

  //Function to publish marker
  void PublishMarker()
  {
   
    pub_.publish(marker);

  }


  //Function to toggle marker visibility
  void ToggleVisibility(){
   if(marker.color.a == 1.0){
      marker.color.a = 0.0;
     }
   else
     marker.color.a = 1.0;
  }

  //Function to change position of marker
  void SetMarkerPosition (double x,double y, double z){

    // Set the pose of the marker
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = z;
  }

private:
  //Private variables
  ros::NodeHandle n_; 
  ros::Publisher pub_;
 
};

int main( int argc, char** argv )
{

    ros::init(argc, argv, "add_markers");

    //Call AddMarkers constructor
    AddMarkers newAddMarkers;



  while (ros::ok())
  {

    //Set marker to pick up position
    newAddMarkers.SetMarkerPosition(3.365037, -0.582207, 0.0);

    // Publish the marker

    newAddMarkers.PublishMarker();

     ROS_INFO("Marker at startup area.");

    // Wait 5 seconds
    ros::Duration(5.0).sleep();

    //Make marker invisible for 5 seconds to simulate pickup
    newAddMarkers.ToggleVisibility();
    newAddMarkers.PublishMarker();
     ROS_INFO("Marker hidden.");
    ros::Duration(5.0).sleep();

    //Move marker to drop off location and make it visible again
    newAddMarkers.SetMarkerPosition(2.129379, 1.747994, 0.0);
    newAddMarkers.ToggleVisibility();
    newAddMarkers.PublishMarker();
    ROS_INFO("Marker at new location.");

    ros::Duration(5.0).sleep();
  }
}

