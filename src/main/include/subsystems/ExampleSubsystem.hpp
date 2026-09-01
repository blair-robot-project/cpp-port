#include "Subsystem.hpp"

class ExampleSubsystem : public Subsystem {
public:
    ExampleSubsystem();
    bool ExampleState();
private:
    void init() override;
    void periodic() override;
};
// Globally accessible to be used in commands
extern ExampleSubsystem examplesubsystem;