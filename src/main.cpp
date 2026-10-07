#include <iostream>
#include "flight/FlightData.hpp"
#include "sensors/SimulatedSensor.hpp"

int main()
{
    std::cout << "AeroCore Flight Computer \n";
    std::cout << "System status : Online\n";

    SimulatedSensor sensor;
    FlightData data = sensor.read();

    std::cout << "Altitude: " << data.altitude << " ft\n";

    return 0;
}