// Auto registering diagnostic subsystem class
#pragma once

#include <wpi/commands2/SubsystemBase.hpp>
#include <wpi/nt/DoubleTopic.hpp>

/* A modular Subsystem class with diagnostics */
class Subsystem : public wpi::cmd::SubsystemBase {
public:
    // Base subsystem constructor which takes in a name
    Subsystem(std::string subsystem_name);
    // Default destructor
    virtual ~Subsystem() noexcept;
    // Initialize all subsystems
    static void initSubsystems();
protected:
    // All hardware should be initialized in init
    virtual void init();
    // Periodic will run once every 20ms
    virtual void periodic();
private:
    // Networktables periodic execution time publisher
    wpi::nt::DoublePublisher execution_time;
    // Reserved for measuring the efficiency of periodic()
    void Periodic() override;
};