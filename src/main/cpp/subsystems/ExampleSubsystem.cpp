#include "Subsystem.hpp"

class ExampleSubsystem : public Subsystem {
    const int priority = 0;
    void init() {

    }
    void periodic() {
    
    }
};
// Register subsystem
ExampleSubsystem examplesubsystem;