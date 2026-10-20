#include "hardware/Motor.hpp"
#include <rev/SparkMax.h>
#include <rev/sim/SparkMaxSim.h>
#include <wpi/nt/BooleanTopic.hpp>
#include <wpi/nt/StringTopic.hpp>

class SparkMax : public Motor {
public:
    // Motor Models
    enum class Model {
        NEO,
        NEO550,
        CIM
    };
    // Constructor
    SparkMax(std::string spark_name, wpi::CANPort spark_port, int spark_id, bool spark_inverted = false, bool spark_brushless = true, Model spark_model = Model::NEO, bool spark_diagnostics = true);
    ~SparkMax();
    // Sets the voltage of the motor
    void setVoltage(wpi::units::volt_t voltage);
    // Sets the throttle of the motor to a value between -1 and 1
    void setThrottle(double throttle);
    // Gets the current throttle of the motor
    double getThrottle();
    // Stops the motor
    void stop();
    // Disables the motor
    void disable();
private:
    bool brushless;
    Model model;
    std::string modelname;
    wpi::nt::BooleanPublisher diagnostic_spark_brushless;
    wpi::nt::StringPublisher diagnostic_spark_model;
    rev::spark::SparkMax* spark;
    wpi::math::DCMotor motor;
    rev::spark::SparkMaxSim* spark_sim;
    rev::spark::SparkAbsoluteEncoder* encoder;
    void real_init() override;
    void simulated_init() override;
    void real_periodic() override;
    void simulated_periodic() override;
};