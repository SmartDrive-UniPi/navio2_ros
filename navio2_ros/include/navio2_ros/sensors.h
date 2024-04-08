#ifndef NAVIO2_ROS_SENSORS_H
#define NAVIO2_ROS_SENSORS_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"

#include "navio2_ros/imu.h"

class NavioSensors : public rclcpp::Node {
public:
    NavioSensors();

private:
    Navio2::Imu imu_mpu_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr publisher_imu_mpu_;

    void timer_callback();
};
#endif //NAVIO2_ROS_SENSORS_H
