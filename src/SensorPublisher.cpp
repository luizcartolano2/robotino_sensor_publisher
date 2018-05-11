//
// Created by Cartolano on 02/11/17.
//
#include "../include/SensorPublisher.hpp"
#include "std_msgs/String.h"

using namespace std;

SensorPublisher::SensorPublisher()
{
    distance_sensors_sub_ = nh_.subscribe("distance_sensors", 1, &SensorPublisher::IRCallback, this);
    distance_sensors_pub_ = nh_.advertise<sensor_msgs::PointCloud>("sensor_publisher", 1);
}

void SensorPublisher::IRCallback(const sensor_msgs::PointCloud::ConstPtr& msg)
{
        
    distances_msg_.points.resize(8);	

    for (int i = 1; i < 9; i++)
    {
        distances_msg_.points[i-1].x  = msg->points[i].x;
        distances_msg_.points[i-1].y = msg->points[i].y;
        distances_msg_.points[i-1].z = msg->points[i].z;
    }


// Build the PointCloud msg
    distances_msg_.header.stamp = msg->header.stamp;
    distances_msg_.header.frame_id = "sensor_publisher_link";

    // Publish the message
    distance_sensors_pub_.publish(distances_msg_);

}

