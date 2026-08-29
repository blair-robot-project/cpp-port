// Base Auto Class
#include <string>
#include <map>
#include <functional>

#define DEFAULT_AUTO "Default"
class Auto {
public:
    // Static members
    static std::map<std::string, Auto*>& getAutos(); // Get auto list
    
    // Base constructor which adds autos to the auto list
    Auto();
    // Auto display name
    const char* name = "";
    // Auto callbacks
    virtual void init();
    virtual void periodic();
};