// Hardware
#pragma once

#include <string>
#include <wpi/nt/NetworkTable.hpp>
#include <wpi/nt/BooleanTopic.hpp>
#include <wpi/commands2/CommandScheduler.hpp>

// Hardware is initialized inside of subsystems
class Hardware {
public:
    // Constructor which takes in a name for diagnostics
    Hardware(std::string hardware_name, bool hardware_diagnostics);
    // Enable or disable diagnostics updating
    void init();
    void periodic();
protected:
    bool simulated;
    std::string name;
    bool diagnostics;
    std::shared_ptr<wpi::nt::NetworkTable> diagnostic_table;
    wpi::nt::BooleanPublisher diagnostic_initialized;
    virtual void real_init() = 0;
    virtual void simulated_init() = 0;
    virtual void real_periodic() = 0;
    virtual void simulated_periodic() = 0;
};