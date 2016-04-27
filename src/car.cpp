
#include <ros/ros.h>
#include "std_msgs/String.h"
#include "anro1/point.h"




/**
 * Subskrybenci swiatel i zakretow
 */
void lights_infoCallback(const anro1::point::ConstPtr& msg)
{
  ROS_INFO("I heard point:" );
}




  //ROS_WARN_STREAM("Marker ID : " << marker.id << " x = " << (float)marker.pose.position.x
                //  << " y = " << (float) marker.pose.position.y);


int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(30);
  /*Publishers*/
  
  /*Subscribers*/	
  ros::Subscriber lights_info_pub = n.subscribe("nodes_info", 1000, lights_infoCallback);

  

  while (ros::ok())
  {
    ros::spinOnce();
  }
}
