#include "Auto.hpp"

// Create auto
class ExampleAuto : public Auto {
public:
    // Set name
    ExampleAuto() : Auto("Example Auto") {}
    // Command
    void init() override {
        // Init code goes here
    }
    void periodic() override {
        // Periodic code goes here
    }
};
// Register auto
ExampleAuto exampleauto;