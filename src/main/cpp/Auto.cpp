#include "Auto.hpp"

// Auto list
std::map<std::string, std::reference_wrapper<Auto>>* auto_list = nullptr;
Auto::Auto() {
    // Create auto list if it doesn't exist yet
    if (auto_list == nullptr)
        auto_list = new std::map<std::string, std::reference_wrapper<Auto>>();
    // Add auto
    std::map<std::string, std::reference_wrapper<Auto>>& autos = *auto_list;
    autos[this->name] = *this;
}
std::map<std::string, std::reference_wrapper<Auto>> getAutos() {
    // Return empty map if there are no registered autos
    if (auto_list == nullptr)
        return {};
    return *auto_list;
}