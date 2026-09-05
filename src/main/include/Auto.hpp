// Register Auto OpMode
#pragma once

#include "RegisteredOpMode.hpp"

/* The Auto class is used to register a wpi::OpMode as an auto */
template <wpi::ConstructibleOpMode<Robot> T>  // Auto passed as a wpi::OpMode template
class Auto : public RegisteredOpMode<T> {
public:
    // Constructor adds auto to list to be registered as an OpMode
    inline Auto(std::string auto_name, std::string auto_group = "", std::string auto_description = "") :
    RegisteredOpMode<T>::RegisteredOpMode(wpi::RobotMode::AUTONOMOUS, auto_name, auto_group, auto_description) {}
};