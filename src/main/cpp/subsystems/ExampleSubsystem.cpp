#include "subsystems/ExampleSubsystem.hpp"
#include <wpi/util/print.hpp>

// Name for diagnostics
ExampleSubsystem::ExampleSubsystem() : Subsystem("Example Subsystem") {
}

// Implement methods
void ExampleSubsystem::init() {
    motor = new SparkMax("Test Motor", wpi::CANPort::CAN_S0, 15);
    motor->init();
}
void ExampleSubsystem::periodic() {
    motor->periodic();
}