#include "Auto.hpp"

// Auto list
std::map<std::string, Auto*>* auto_list = nullptr;
Auto::Auto() {
    // Create auto list if it doesn't exist yet
    if (auto_list == nullptr)
        auto_list = new std::map<std::string, Auto*>();
    // Add auto
    auto_list->insert({this->name, this});
}
std::map<std::string, Auto*>& Auto::getAutos() {
    // Create auto list if it doesn't exist yet
    if (auto_list == nullptr)
        auto_list = new std::map<std::string, Auto*>();
    return *auto_list;
}
void Auto::init() {}
void Auto::periodic() {}