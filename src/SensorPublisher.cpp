//
// Created by Cartolano on 02/11/17.
//
#include "../include/SensorPublisher.hpp"
#include "std_msgs/String.h"

SensorPublisher::SensorPublisher() {
  nh_(),
  node_loop_rate_(20)
  {
    distance_sensors_sub_ = nh_.subscribe("distance_sensors", 100, &SensorPublisher::IRCallback, this);
    distance_sensors_pub_ = nh_.advertise<sensor_msgs::PointCloud>("eight_sensor", 100, true);
  }
}

SensorPublisher::~SensorPublisher() {
  distance_sensors_sub_.shutdown();
}

SensorPublisher::setTimeStamp(ros::Time stamp)
{
  stamp_ = stamp;
}

void SensorPublisher::IRCallback(const sensor_msgs::PointCloud::ConstPtr& msg)
{
  for (int i = 1; i < 9; i++) {
    std::array<float, 3> points{0};
    points[0] = (msg->points[i]).x;
    points[1] = (msg->points[i]).y;
    points[2] = (msg->points[i]).z;
    dist_vect_.push_back(points);
  }
}

void SensorPublisher::spin()
{
  ros::Rate lr(node_loop_rate_);

  while(nh_.ok())
  {

    // Build the PointCloud msg
  	distances_msg_.header.stamp = stamp_;
  	distances_msg_.header.frame_id = "eight_sensor_link";
    distances_msg_.points.resize(8);

    for (unsigned int i = 0; i < 8; i++) {
      distances_msg_.points[i].x = dist_vect_[i][0];
      distances_msg_.points[i].y = dist_vect_[i][1];
      distances_msg_.points[i].z = dist_vect_[i][2];
    }

    // Publish the message
    distance_sensors_pub_.publish(distances_msg_);

    ros::spinOnce();
    lr.sleep();

  }
}
