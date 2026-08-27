// Base Subsystem Class

class Subsystem {
public:
    // Static Members
    static void initSubsystems();   // Calls init() on all subsystems in their priority order
    static void periodicSubsystems();   // Calls periodic() on all subsystems in their priority order

    // Base Constructor which adds th
    Subsystem();
    // Subsystem priority
    const int priority = 0;

    // Subsystem callbacks
    virtual void init();
    virtual void periodic();
};