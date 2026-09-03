#include "RegisteredOpMode.hpp"
#include <vector>

// OpMode list
std::vector<RegisteredOpModeBase*>* opmode_list = nullptr;
// Base constructor
RegisteredOpModeBase::RegisteredOpModeBase() {
    // Create OpMode list if it doesn't exist yet
    if (opmode_list == nullptr)
        opmode_list = new std::vector<RegisteredOpModeBase*>();
    // Add OpMode to list
    opmode_list->push_back(this);
}
// Add all OpModes in list
void RegisteredOpModeBase::addOpModes(Robot& robot) {
    if (opmode_list != nullptr) for (RegisteredOpModeBase* opmode : *opmode_list)
        opmode->addOpMode(robot);
}