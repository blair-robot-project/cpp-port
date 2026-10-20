// Base CAN Device Class
#pragma once

#include "hardware/Hardware.hpp"
#include <wpi/units/voltage.hpp>
#include <wpi/hardware/bus/CAN.hpp>
#include <wpi/nt/IntegerTopic.hpp>

class CANDevice : public Hardware {
public:
    CANDevice(std::string device_name, wpi::CANPort device_port, int device_id, bool device_diagnostics = true);
    virtual ~CANDevice() = default;
protected:
    wpi::CANPort port;
    int id;
    virtual void real_init() override = 0;
    virtual void simulated_init() override = 0;
    virtual void real_periodic() override = 0;
    virtual void simulated_periodic() override = 0;
private:
    wpi::nt::IntegerPublisher diagnostic_can_port;
    wpi::nt::IntegerPublisher diagnostic_can_id;
};