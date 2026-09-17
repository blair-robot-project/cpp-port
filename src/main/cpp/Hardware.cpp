#include "Hardware.hpp"
#include "Robot.hpp"

#include <wpi/nt/NetworkTableInstance.hpp>

Hardware::Hardware(std::string name) {
    // Initialize diagnostic table
    wpi::nt::NetworkTableInstance nt = wpi::nt::NetworkTableInstance::GetDefault();
    diagnostic_table = nt.GetTable("Hardware")->GetSubTable(name);
}

void Hardware::init() {
    if (robot->IsSimulation)
        simulated_init();
    else
        real_init();
}
void Hardware::periodic() {
    if (robot->IsSimulation)
        simulated_periodic();
    else
        real_periodic();
}