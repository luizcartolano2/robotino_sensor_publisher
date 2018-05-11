//
// Created by Cartolano on 02/11/17.
//
#include "ros/ros.h"
#include "../include/SensorPublisher.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sensor_publisher");

  /**
    * O objeto SensorPublisher é responsável por receber uma mensagem de /distance_sensors
    e publicar a distancia lida pelos sensores ignorando o sensor de numero 1 (sensor frontal)
  */
  SensorPublisher distance_sensors;
  ros::spin();

  return 0;
}

