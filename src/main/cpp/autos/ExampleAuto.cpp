#include "Auto.hpp"

// Create auto
class Example : public Auto {
    const std::string name = "Example Auto";
    void init() {
        // Init code goes here
    }
    void periodic() {
        // Periodic code goes here
    }
};
// Register auto
Example registered;