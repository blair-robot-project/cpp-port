#include "Auto.hpp"

// Create auto
class ExampleAuto : public Auto {
    const char* name = "Example Auto";
    void init() {
        // Init code goes here
    }
    void periodic() {
        // Periodic code goes here
    }
};
// Register auto
ExampleAuto exampleauto;