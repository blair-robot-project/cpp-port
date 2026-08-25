#include "Auto.hpp"

// Auto list
std::map<std::string, std::reference_wrapper<Auto>>* auto_list = nullptr;
Auto::Auto() {
    // Create auto list if it doesn't exist yet
    if (auto_list == nullptr)
        auto_list = new std::map<std::string, std::reference_wrapper<Auto>>();
    // Add auto
    auto_list->[this->name] = *this;
}
std::map<std::string, std::reference_wrapper<Auto>> getAutos() {

}