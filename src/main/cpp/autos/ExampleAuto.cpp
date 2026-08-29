#include "Auto.hpp"

// Create auto
class ExampleAuto : public Auto {
public:
    // Set name
    ExampleAuto() : Auto("Example Auto") {}
    // Callbacks
    void init() {
        // Init code goes here
    }
    void periodic() {
        // Periodic code goes here
    }
};
// Register auto
ExampleAuto exampleauto;