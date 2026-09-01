// Base Auto Class
#include <string>
#include <map>

#include <wpi/commands2/Command.hpp>

#define DEFAULT_AUTO "Default"
class Auto {
public:
    // Static members
    static std::map<std::string, Auto*>& getAutos(); // Get auto list
    
    // Base constructor which adds autos to the auto list
    Auto(std::string auto_name);    

    // Auto callbacks
    virtual void init();
    virtual void periodic();
};