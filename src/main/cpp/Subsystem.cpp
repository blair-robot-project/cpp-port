#include "Subsystem.hpp"

#include <wpi/util/print.hpp>

#include <vector>
#include <chrono>

#include <wpi/nt/DoubleTopic.hpp>
#include <wpi/nt/NetworkTable.hpp>
#include <wpi/nt/NetworkTableInstance.hpp>

// Add subsystem to list
std::vector<Subsystem*>* subsystem_list = nullptr;
Subsystem::Subsystem(std::string subsystem_name) {
    SetName(subsystem_name);
    // Create subsystem list if it doesn't exist yet
    if (subsystem_list == nullptr)
        subsystem_list = new std::vector<Subsystem*>;
    // Register subsystem
    subsystem_list->push_back(this);
    wpi::util::println("Registered Subsystem: {}", subsystem_name);
}
// Default destructor
Subsystem::~Subsystem() {}
// Initialize all subsystems
void Subsystem::initSubsystems() {
    // Initialize diagnostics
    wpi::nt::NetworkTableInstance nt = wpi::nt::NetworkTableInstance::GetDefault();
    std::shared_ptr<wpi::nt::NetworkTable> table = nt.GetTable("Subsystem Periodic Execution Time (ms)");
    // Initialize subsystems if the subsystem list exists
    if (subsystem_list != nullptr) for (Subsystem* subsystem : *subsystem_list) {
        subsystem->init();
        subsystem->execution_time = table->GetDoubleTopic(subsystem->GetName()).Publish();
        wpi::util::println("Initialized Subsystem: {}", subsystem->GetName());
    }
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
    const std::chrono::duration<double, std::milli> time = end - start;
    execution_time.Set(time.count());
}