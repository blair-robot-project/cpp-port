// Register Teleop OpMode
#pragma once

#include "RegisteredOpMode.hpp"

/* The Teleop class is used to register a wpi::OpMode as a teleop */
template <wpi::ConstructibleOpMode<Robot> T>  // Auto passed as a wpi::OpMode template
class Teleop : public RegisteredOpMode<T> {
public:
    // Constructor adds the teleop to the list to be registered as an OpMode
    inline Teleop(std::string teleop_name, std::string teleop_description = "", std::string teleop_group = "") :
    RegisteredOpMode<T>::RegisteredOpMode(wpi::RobotMode::TELEOPERATED, teleop_name, teleop_group, teleop_description) {}
};