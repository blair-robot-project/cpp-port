# cpp-port
A WPILib C++ port of the robot code using the OpMode framework and Commands V2

## Systems
### OpModes
OpModes are automatically added using a system similar to annotations.
```cpp
// The Java version of the OpMode framework allows for a @Auto, @Teleop, or an @Utility decorator before an OpMode to automatically register it.
// The C++ version doesn't, so I made an equivalent system
class ExampleOpMode : wpi::PeriodicOpMode {
    ExampleOpMode() {}
    void Start() override {}
    void Periodic() override {}
    void End() override {}
}
// The decorator equivalent goes after the OpMode
RegisteredOpMode<ExampleOpMode> exampleopmode(MODE, "name", "group", "description");
// There are three classes which inherit RegisteredOpMode to make it even more similar to the decorator version: Auto, Teleop, and Utility. They function the same as RegisteredOpMode but automatically fill in the MODE parameter, they should always be used instead of this underlying class for clarity.
```
Check out [`ExampleAuto.cpp`](src/main/cpp/opmode/auto/ExampleAuto.cpp), [`ExampleTeleop.cpp`](src/main/cpp/opmode/teleop/ExampleTeleop.cpp), and [`ExampleUtility.cpp`](src/main/cpp/opmode/utility/ExampleUtility.cpp) to see the system in action. Run a simulation and see how they all appear in the OpMode selector.
#### How it works
When a `RegisteredOpMode` is declared as a global class like this, the constructor runs before the program starts, adding the class to an internal list which is tracked in [`RegisteredOpMode.cpp`](src/main/cpp/RegisteredOpMode.cpp). Once the robot program is ready, all of the RegisteredOpModes in the list add their OpMode to the robot.

### Subsystems
Subsystems are automatically added to the robot in a similar way to the OpModes. Subsystem periodic performance is added to networktables automatically under `Subsystem Periodic Execution Time (ms)`. This can be graphed in AdvantageScope to compare the performance of different subsystems.  
Unlike OpModes, Subsystems require a header to define the available functions and a separate source file to define the implementations. The header files become a sort of documentation for how a subsystem can be used.
```cpp
// ExampleSubsystem.hpp
class ExampleSybsystem : Subsystem() {
    // No hardware should be initialized in the constructor
    // The purpose of the constructor is to add the subsystem to a list and to pass a name to be used for the periodic execution time diagnostics.
    ExampleSubsystem();
    // All hardware is initialized here
    void init() override;
    // Is run and timed every 20ms
    void periodic() override;
}
```
```cpp
// ExampleSubsystem.cpp

// Pass the subsystem name to the parent class for diagnostics
ExampleSubsystem::ExampleSubsystem() : Subsystem("Subsystem Name") {}

void ExampleSubsystem::init() {}
void ExampleSubsystem::periodic() {}
```
The subsystem can be added to the robot by simply adding it to the `Robot` class in the [`Robot.hpp`](src/main/include/Robot.hpp) header file as a `public` member.
```cpp
class Robot : wpi::OpModeRobot<Robot> {
public:
    // Subsystems
    ExampleSubsystem examplesubsystem;
    ...
}
```