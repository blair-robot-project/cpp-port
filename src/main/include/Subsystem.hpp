#include <wpi/commands2/SubsystemBase.hpp>

/* A modular Subsystem class with diagnostics */
class Subsystem : public wpi::cmd::SubsystemBase {
public:
    // Base subsystem constructor which takes in a name for diagnostics
    Subsystem(std::string subsystem_name);
    
protected:
    // All hardware should be initialized in init
    virtual void init();
    // Periodic will run once every 20ms
    virtual void periodic();
private:
    // Reserved for measuring the efficiency of periodic()
    void Periodic() override;
    // Name for diagnostics
    std::string name;
};