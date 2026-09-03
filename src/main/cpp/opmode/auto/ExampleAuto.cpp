#include "Auto.hpp"

#include "subsystems/ExampleSubsystem.hpp"

// Create auto
class ExampleAuto : public wpi::PeriodicOpMode {
public:
    // Constructor
    ExampleAuto(Robot& robot) : robot{robot} {}
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
// Register auto
Auto<ExampleAuto> exampleauto("Example Auto", "An example auto", "examples");