#include "Teleop.hpp"

#include "subsystems/ExampleSubsystem.hpp"

// Create teleop
class ExampleTeleop : public wpi::PeriodicOpMode {
public:
    // Constructor
    ExampleTeleop(Robot& robot) : robot{robot} {}
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
// Register teleop
Teleop<ExampleTeleop> exampleteleop("Example Teleop", "An example teleop", "examples");