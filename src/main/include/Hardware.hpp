// Hardware
#pragma once

#include <string>
#include <wpi/nt/NetworkTable.hpp>

// Hardware is initialized inside of subsystems
class Hardware {
public:
    // Constructor which takes in a name for diagnostics
    Hardware(std::string name);
    void init();
    void periodic();
protected:
    std::shared_ptr<wpi::nt::NetworkTable> diagnostic_table;
    virtual void real_init();
    virtual void simulated_init();
    virtual void real_periodic();
    virtual void simulated_periodic();
};