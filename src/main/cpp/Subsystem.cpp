#include "Subsystem.hpp"

#include <wpi/util/print.hpp>

#include <chrono>

Subsystem::Subsystem(std::string subsystem_name) {
    name = subsystem_name;
    wpi::util::println("Subsystem registered: {}", name);
}
void Subsystem::init() {}
void Subsystem::periodic() {}

// Time subsystem periodic
void Subsystem::Periodic() {
    // Get start time
    const std::chrono::time_point start = std::chrono::steady_clock::now();
    // Call subsystem periodic
    periodic();
    // Calculate nanoseconds
    const std::chrono::time_point end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> time{end-start};
}