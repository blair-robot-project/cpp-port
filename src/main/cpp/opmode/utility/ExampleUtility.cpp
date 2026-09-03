#include "Utility.hpp"

#include "subsystems/ExampleSubsystem.hpp"

// Create utility
class ExampleUtility : public wpi::PeriodicOpMode {
public:
    // Constructor
    ExampleUtility(Robot& robot) : robot{robot} {}
    Robot& robot;
    // Callbacks
    void Start() override {
        // Init code goes here
    }
    void Periodic() override {
        // Periodic code goes here
    }
    void End() override {
        // End code goes here
    }
};
// Register utility
Utility<ExampleUtility> exampleutility("Example Utility", "An example utility", "examples");