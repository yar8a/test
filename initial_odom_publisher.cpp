#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "initial_odom_publisher");
  ros::NodeHandle nh;

  ros::Publisher odom_pub = nh.advertise<nav_msgs::Odometry>("/odom", 10);

  // Initial pose
  geometry_msgs::Pose initial_pose;
  initial_pose.position.x = 1.0;
  initial_pose.position.y = 0.0;
  initial_pose.position.z = 0.0;
  initial_pose.orientation.x = 0.0;
  initial_pose.orientation.y = 0.0;
  initial_pose.orientation.z = 0.0;
  initial_pose.orientation.w = 1.0;  // Assuming no rotation initially

  nav_msgs::Odometry initial_odom;
  initial_odom.header.stamp = ros::Time::now();
  initial_odom.header.frame_id = "odom";
  initial_odom.child_frame_id = "base_footprint"; // or "base_link" depending on your setup
  initial_odom.pose.pose = initial_pose;

  // Publish the initial odom message a few times to ensure it gets through
  for (int i = 0; i < 10; ++i) {
    odom_pub.publish(initial_odom);
    ros::Duration(0.1).sleep();
  }

  ros::spinOnce();
  return 0;
}
