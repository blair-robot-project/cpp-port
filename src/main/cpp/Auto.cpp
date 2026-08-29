#include "Auto.hpp"
#include "wpi/util/print.hpp"

// Auto list
std::map<std::string, Auto*>* auto_list = nullptr;
Auto::Auto(std::string name) {
    // Create auto list if it doesn't exist yet
    if (auto_list == nullptr)
        auto_list = new std::map<std::string, Auto*>();
    // Register auto
    auto_list->insert({name, this});
    wpi::util::println("Auto {} registered!", name);
}
std::map<std::string, Auto*>& Auto::getAutos() {
    // Create auto list if it doesn't exist yet
    if (auto_list == nullptr)
        auto_list = new std::map<std::string, Auto*>();
    return *auto_list;
}
void Auto::init() {}
void Auto::periodic() {}

Auto defaultAuto(DEFAULT_AUTO);