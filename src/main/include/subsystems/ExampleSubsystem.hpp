#pragma once
#include "Subsystem.hpp"

#include "hardware/motors/SparkMax.hpp"

class ExampleSubsystem : public Subsystem {
public:
    ExampleSubsystem();
    bool ExampleState();

    // Hardware
    SparkMax* motor;
private:
    void init() override;
    void periodic() override;
};