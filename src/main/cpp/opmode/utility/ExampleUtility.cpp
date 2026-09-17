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
        wpi::util::print("Example utility start!");
    }
    void Periodic() override {
        // Periodic code goes here
        wpi::util::print("Example utility!");
    }
    void End() override {
        // End code goes here
        wpi::util::print("Example utility end!");
    }
};
// Register utility
Utility<ExampleUtility> exampleutility("Example Utility", "An example utility", "examples");