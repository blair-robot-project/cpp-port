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
        wpi::util::println("Example teleop start!");
    }
    void Periodic() override {
        // Periodic code goes here
        wpi::util::println("Example teleop!");
    }
    void End() override {
        // End code goes here
        wpi::util::println("Example teleop end!");
    }
};
// Register teleop
Teleop<ExampleTeleop> exampleteleop("Example Teleop", "An example teleop", "examples");