// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.hpp"

#include <wpi/util/print.hpp>

#include <wpi/commands2/CommandScheduler.hpp>

#include "RegisteredOpMode.hpp"
#include "Subsystem.hpp"

// Constructor
Robot* robot = nullptr;
Robot::Robot() {
  // Make robot globally accessible
  robot = this;
  // Initialize Subsystems
  Subsystem::initSubsystems();
  wpi::util::println("Initialized All Subsystems");
  // Add and publish all OpModes
  RegisteredOpModeBase::addOpModes(*this);
  PublishOpModes();
  wpi::util::println("Added All OpModes");
}

void Robot::RobotPeriodic() {
  // Run commands and subsystems
  wpi::cmd::CommandScheduler::GetInstance().Run();
}

// Driver Station Connected
void Robot::DriverStationConnected() {}

// No OpMode enabled
void Robot::NonePeriodic() {}

// Disabled
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::DisabledExit() {}

// Simulation
void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_WPILIB_TESTS
int main() {
  return wpi::StartRobot<Robot>();
}
#endif
