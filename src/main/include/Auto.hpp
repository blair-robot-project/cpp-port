// Base Auto Class
#include <string>
#include <map>
#include <functional>

class Auto {
    static std::map<std::string, std::reference_wrapper<Auto>> getAutos(); // Get auto list
public:
    // Base constructor which adds autos to the auto list
    Auto();
    // Auto display name
    const std::string name = "";
    // Auto callbacks
    virtual void init();
    virtual void periodic();
};