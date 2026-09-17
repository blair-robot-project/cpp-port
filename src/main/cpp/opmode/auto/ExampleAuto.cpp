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
        wpi::util::println("Example auto start!");
    }
    void Periodic() override {
        // Periodic code goes here
        wpi::util::println("Example auto!");
    }
    void End() override {
        // End code goes here
        wpi::util::println("Example auto end!");
    }
};
// Register auto
Auto<ExampleAuto> exampleauto("Example Auto", "An example auto", "examples");