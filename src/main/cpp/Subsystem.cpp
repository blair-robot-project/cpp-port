#include "Subsystem.hpp"
#include <map>

std::multimap<int, Subsystem*>* subsystem_list = nullptr;
Subsystem::Subsystem() {
    // Create subsystem list if it doesn't exist yet
    if (subsystem_list == nullptr)
        subsystem_list = new std::multimap<int, Subsystem*>();
    subsystem_list->insert({this->priority, this});
}

void Subsystem::initSubsystems() {
    // Create subsystem list if it doesn't exist yet
    if (subsystem_list == nullptr)
        subsystem_list = new std::multimap<int, Subsystem*>();
    // Init subsystems
    for (const auto& [priority, subsystem] : *subsystem_list) {
        subsystem->init();
    }
}
void Subsystem::periodicSubsystems() {
    // Create subsystem list if it doesn't exist yet
    if (subsystem_list == nullptr)
        subsystem_list = new std::multimap<int, Subsystem*>();
    // Init subsystems
    for (const auto& [priority, subsystem] : *subsystem_list) {
        subsystem->periodic();
    }
}
void Subsystem::init() {}
void Subsystem::periodic() {}