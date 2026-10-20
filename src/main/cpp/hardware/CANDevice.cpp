#include "hardware/CANDevice.hpp"
#include <wpi/nt/IntegerTopic.hpp>

CANDevice::CANDevice(std::string device_name, wpi::CANPort device_port, int device_id, bool device_diagnostics) : Hardware(device_name, device_diagnostics) {
    port = device_port;
    id = device_id;
    // Add data to diagnostic table
    diagnostic_can_port = Hardware::diagnostic_table->GetIntegerTopic("CAN Port").Publish();
    diagnostic_can_id = Hardware::diagnostic_table->GetIntegerTopic("CAN Id").Publish();
    diagnostic_can_port.Set((int)device_port);
    diagnostic_can_id.Set(device_id);

}
