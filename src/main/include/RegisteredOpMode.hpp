// Register an OpMode
#pragma once

#include <wpi/opmode/OpMode.hpp>
#include <wpi/opmode/PeriodicOpMode.hpp>
#include <wpi/util/print.hpp>

#include "Robot.hpp"

#include <string>

/* Base class for registering OpModes */
class RegisteredOpModeBase {
public:
    // Base constructor which adds the OpMode to a list
    RegisteredOpModeBase();
    // Add all OpModes to the robot
    static void addOpModes(Robot& robot);
    // Default Destructor
    ~RegisteredOpModeBase() = default;
protected:
    // Add OpMode to the robot
    virtual void addOpMode(Robot& robot) = 0;
};

/* Class for registering OpModes */
template <wpi::ConstructibleOpMode<Robot> T>    // wpi::OpMode passed as a template
class RegisteredOpMode : public RegisteredOpModeBase {
public:
    // Constructor to get OpMode parameters
    inline RegisteredOpMode(wpi::RobotMode opmode_mode, std::string opmode_name, std::string opmode_group, std::string opmode_description) {
        mode = opmode_mode;
        name = opmode_name;
        group = opmode_group;
        description = opmode_description;
        wpi::util::println("Registered OpMode: {}", name);
    }
    // Don't inherit addOpModes
    static void addOpModes(Robot& robot) = delete;
private:
    // Add OpMode to robot
    inline void addOpMode(Robot& robot) {
        robot.AddOpMode<T>(mode, name, group, description);
        wpi::util::println("Added OpMode: {}", name);
    }
    // OpMode parameters
    wpi::RobotMode mode;
    std::string name;
    std::string group;
    std::string description;
};