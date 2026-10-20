#include "hardware/motors/SparkMax.hpp"
#include <wpi/math/system/DCMotor.hpp>
#include <wpi/util/print.hpp>
#include <wpi/commands2/Commands.hpp>
#include <wpi/commands2/button/Trigger.hpp>

SparkMax::SparkMax(std::string spark_name, wpi::CANPort spark_port, int spark_id, bool spark_inverted, bool spark_brushless, Model spark_model, bool spark_diagnostics)
: Motor(spark_name, spark_port, spark_id, spark_inverted, spark_diagnostics),
motor{wpi::math::DCMotor::NEO(1)} {
    brushless = spark_brushless;
    model = spark_model;
    switch (model) {
        case SparkMax::Model::NEO:
            modelname = "NEO";
            break;
        case SparkMax::Model::NEO550:
            modelname = "NEO550";
            break;
        case SparkMax::Model::CIM:
            modelname = "CIM";
            break;
        default:
            modelname = "Invalid";
    }
    // Add data to diagnostic table
    diagnostic_spark_brushless = Hardware::diagnostic_table->GetBooleanTopic("SparkMax Brushless").Publish();
    diagnostic_spark_model = Hardware::diagnostic_table->GetStringTopic("SparkMax Model").Publish();
    diagnostic_spark_brushless.Set(spark_brushless);
    diagnostic_spark_model.Set(modelname);
}

SparkMax::~SparkMax() {
    if (spark != nullptr)
        delete spark;
    if (spark_sim != nullptr)
        delete spark_sim;
}

inline rev::spark::SparkMax* create_sparkmax(wpi::CANPort port, int id, bool inverted, bool brushless) {
    rev::spark::SparkMax* spark = new rev::spark::SparkMax(port, id, brushless ? rev::spark::SparkLowLevel::MotorType::kBrushless : rev::spark::SparkLowLevel::MotorType::kBrushed);
    spark->SetInverted(inverted);
    return spark;
}

void SparkMax::real_init() {
    spark = create_sparkmax(CANDevice::port, CANDevice::id, inverted, brushless);
    encoder = &spark->GetAbsoluteEncoder();
    wpi::cmd::Trigger([&]{return Hardware::diagnostics;}).WhileTrue((wpi::cmd::RunOnce([&]{
        Motor::diagnostic_motor_velocity.Set(encoder->GetVelocity().Get());
        Motor::diagnostic_motor_position.Set(encoder->GetPosition().Get());
        Motor::diagnostic_motor_current.Set(spark->GetOutputCurrent().Get());
    })));
}

void SparkMax::real_periodic() {
}

void SparkMax::simulated_init() {
    spark = create_sparkmax(CANDevice::port, CANDevice::id, inverted, brushless);
    encoder = &spark->GetAbsoluteEncoder();
    switch (model) {
        // NEO
        NEO:
            motor = wpi::math::DCMotor::NEO(1);
            break;
        // NEO550
        NEO550:
            motor = wpi::math::DCMotor::NEO550(1);
            break;
        // CIM
        CIM:
            motor = wpi::math::DCMotor::CIM(1);
            break;
        // Default: NEO
        default:
            motor = wpi::math::DCMotor::NEO(1);
    }
    spark_sim = new rev::spark::SparkMaxSim(spark, &motor);
    spark_sim->SetPosition(0);
    spark_sim->SetVelocity(0);

    wpi::cmd::Trigger([&]{return Hardware::diagnostics;}).WhileTrue((wpi::cmd::RunOnce([&]{
        Motor::diagnostic_motor_velocity.Set(spark_sim->GetAlternateEncoderSim().GetVelocity());
        Motor::diagnostic_motor_position.Set(spark_sim->GetAbsoluteEncoderSim().GetPosition());
        Motor::diagnostic_motor_current.Set(spark_sim->GetMotorCurrent());
    })));
}

void SparkMax::simulated_periodic() {
}

void SparkMax::setVoltage(wpi::units::volt_t voltage) {
    spark->SetVoltage(voltage);
}

void SparkMax::setThrottle(double throttle) {
    spark->SetThrottle(throttle);
}

double SparkMax::getThrottle() {
    return spark->GetThrottle();
}

void SparkMax::stop() {
    spark->StopMotor();
}

void SparkMax::disable() {
    spark->Disable();
}