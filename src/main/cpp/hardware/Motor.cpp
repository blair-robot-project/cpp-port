#include "hardware/Motor.hpp"
#include <limits>

Motor::Motor(std::string motor_name, wpi::CANPort motor_port, int motor_id, bool motor_inverted, bool motor_diagnostics) : CANDevice(motor_name, motor_port, motor_id, motor_diagnostics) {
    inverted = motor_inverted;
    // Add data to diagnostic table
    diagnostic_motor_inverted = Hardware::diagnostic_table->GetBooleanTopic("Motor Inverted").Publish();
    diagnostic_motor_velocity = Hardware::diagnostic_table->GetDoubleTopic("Motor Velocity").Publish();
    diagnostic_motor_current = Hardware::diagnostic_table->GetDoubleTopic("Motor Voltage").Publish();
    diagnostic_motor_position = Hardware::diagnostic_table->GetDoubleTopic("Motor Angle").Publish();
    diagnostic_motor_inverted.Set(motor_inverted);
    // Initalize motor controlled values with NaN
    diagnostic_motor_velocity.SetDefault(std::numeric_limits<double>().quiet_NaN());
    diagnostic_motor_current.SetDefault(std::numeric_limits<double>().quiet_NaN());
    diagnostic_motor_position.SetDefault(std::numeric_limits<double>().quiet_NaN());
}