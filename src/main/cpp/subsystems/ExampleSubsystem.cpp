#include "subsystems/ExampleSubsystem.hpp"

// Name for diagnostics
ExampleSubsystem::ExampleSubsystem() : Subsystem("Example Subsystem") {}

// Implement methods
void ExampleSubsystem::init() {}
void ExampleSubsystem::periodic() {}

// Register subsystem
ExampleSubsystem examplesubsystem;