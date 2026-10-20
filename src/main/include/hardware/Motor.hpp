// Base Motor Class
#pragma once

#include "hardware/CANDevice.hpp"
#include <wpi/units/voltage.hpp>
#include <wpi/hardware/bus/CAN.hpp>
#include <wpi/nt/BooleanTopic.hpp>
#include <wpi/nt/DoubleTopic.hpp>

class Motor : public CANDevice {
public:
    Motor(std::string motor_name, wpi::CANPort motor_port, int motor_id, bool motor_inverted = false, bool motor_diagnostics = true);
    virtual ~Motor() = default;
    // Sets the voltage of the motor
    virtual void setVoltage(wpi::units::volt_t voltage) = 0;
    // Sets the throttle of the motor to a value between -1 and 1
    virtual void setThrottle(double throttle) = 0;
    // Gets the current throttle of the motor
    virtual double getThrottle() = 0;
    // Stops the motor
    virtual void stop() = 0;
    // Disables the motor
    virtual void disable() = 0;
    // Get angle
protected:
    wpi::nt::DoublePublisher diagnostic_motor_velocity;
    wpi::nt::DoublePublisher diagnostic_motor_current;
    wpi::nt::DoublePublisher diagnostic_motor_position;
    bool inverted;
    virtual void real_init() override = 0;
    virtual void simulated_init() override = 0;
    virtual void real_periodic() override = 0;
    virtual void simulated_periodic() override = 0;
private:
    wpi::nt::BooleanPublisher diagnostic_motor_inverted;
};