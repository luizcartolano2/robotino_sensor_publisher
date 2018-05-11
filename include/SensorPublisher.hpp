//
// Created by Cartolano on 02/11/17.
//
#ifndef SENSORPUBLISHER_HPP
#define SENSORPUBLISHER_HPP

// including paths that will be necessary
#include <iostream>
#include <ros/ros.h>
#include "sensor_msgs/PointCloud.h"
#include <sensor_msgs/PointCloud2.h>

class SensorPublisher {
public:
  SensorPublisher();
  void IRCallback(const sensor_msgs::PointCloud::ConstPtr& msg);

private:
  // ROS Handles, Publishers, Subscriber and Messages
  ros::NodeHandle nh_;

  ros::Publisher distance_sensors_pub_;

  ros::Subscriber distance_sensors_sub_;

  sensor_msgs::PointCloud distances_msg_;


};

#endif //DISTANCESENSORS_HPP

