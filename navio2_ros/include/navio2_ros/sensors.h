#ifndef NAVIO2_ROS_SENSORS_H
#define NAVIO2_ROS_SENSORS_H

#include "navio2_ros/imu.h"
#include "navio2_ros/baro_temp.h"

#include <rclcpp/rclcpp.hpp>

#include "navio2_ros/type_adapters/imu_msg.h"
#include <sensor_msgs/msg/fluid_pressure.hpp>
#include <sensor_msgs/msg/temperature.hpp>

class NavioSensors : public rclcpp::Node {
    using ImuMsgAdapter = rclcpp::TypeAdapter<ImuData, sensor_msgs::msg::Imu>;
public:
    NavioSensors();

    ~NavioSensors() override = default;

private:
    Navio2::Imu imu_mpu_;
    Navio2::Imu imu_lsm_;
    Navio2::BaroTemp baro_temp_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<ImuMsgAdapter>::SharedPtr publisher_imu_mpu_;
    rclcpp::Publisher<ImuMsgAdapter>::SharedPtr publisher_imu_lsm_;
    rclcpp::Publisher<sensor_msgs::msg::FluidPressure>::SharedPtr publisher_baro_;
    rclcpp::Publisher<sensor_msgs::msg::Temperature>::SharedPtr publisher_temp_;

    void timer_callback();

    void process_imu(Navio2::InertialSensorType type);

    void publish_imu_data(Navio2::InertialSensorType type, const ImuData &data);

    void publish_baro_data(const double &data);

    void publish_temp_data(const double &data);
};

#endif //NAVIO2_ROS_SENSORS_H
