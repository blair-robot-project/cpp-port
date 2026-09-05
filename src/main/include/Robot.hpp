// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <wpi/framework/OpModeRobot.hpp>

#include "subsystems/ExampleSubsystem.hpp"

class Robot : public wpi::OpModeRobot<Robot> {
public:
  // Subsystems
  ExampleSubsystem examplesubsystem;

  // Constructor
  Robot();
  
  // Callbacks
  void RobotPeriodic() override;
  void DriverStationConnected() override;
  // No OpMode selected
  void NonePeriodic() override;
  // Disabled
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void DisabledExit() override;
  // Simulation
  void SimulationInit() override;
  void SimulationPeriodic() override;
};