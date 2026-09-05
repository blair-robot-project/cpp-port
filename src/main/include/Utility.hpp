// Register Utility OpMode
#pragma once

#include "RegisteredOpMode.hpp"

/* The Utility class is used to register a wpi::OpMode as a utility */
template <wpi::ConstructibleOpMode<Robot> T>  // Auto passed as a wpi::OpMode template
class Utility : public RegisteredOpMode<T> {
public:
    // Constructor adds the utility to the list to be registered as an OpMode
    inline Utility(std::string utility_name, std::string utility_group = "", std::string utility_description = "") :
    RegisteredOpMode<T>::RegisteredOpMode(wpi::RobotMode::UTILITY, utility_name, utility_group, utility_description) {}
};
