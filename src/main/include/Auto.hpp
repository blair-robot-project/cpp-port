// Base Auto Class
#include <string>
#include <map>
#include <functional>

class Auto {
public:
    // Static members
    static const std::string defaultAuto = "Default";
    static std::map<std::string, std::reference_wrapper<Auto>> getAutos(); // Get auto list
    
    // Base constructor which adds autos to the auto list
    Auto();
    // Auto display name
    const std::string name = "";
    // Auto callbacks
    virtual void init();
    virtual void periodic();
};