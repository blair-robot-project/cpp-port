#include "hardware/Hardware.hpp"
#include "Robot.hpp"

#include <wpi/nt/NetworkTableInstance.hpp>

Hardware::Hardware(std::string hardware_name, bool hardware_diagnostics) {
    name = hardware_name;
    diagnostics = hardware_diagnostics;
    // Initialize diagnostic table
    wpi::nt::NetworkTableInstance nt = wpi::nt::NetworkTableInstance::GetDefault();
    diagnostic_table = nt.GetTable("Hardware")->GetSubTable(name);
    // Add entires to diagnostic table
    diagnostic_initialized = diagnostic_table->GetBooleanTopic("Initalized").Publish();
    diagnostic_initialized.Set(false);
}

void Hardware::init() {
    // Each hardware class can only be initialized once
    if (diagnostic_initialized.GetTopic().GetEntry(false))
        return;
    // Run relevant init callback
    if (robot->IsSimulation)
        this->simulated_init();
    else
        this->real_init();
    diagnostic_initialized.Set(true);
}
void Hardware::periodic() {
    // Run relevant periodic callback
    if (robot->IsSimulation)
        this->simulated_periodic();
    else
        this->real_periodic();
}