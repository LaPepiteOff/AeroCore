#include <iostream>
#include "flight/FlightData.hpp"

int main()
{
    std::cout << "AeroCore Flight Computer \n";
    std::cout << "System status : Online\n";

    FlightData data = { 
        .altitude = 10000.0, 
        .airspeed = 250.0, 
        .pitch = 5.0, 
        .roll = 2.0, 
        .temperature = -20.0 
    };

    std::cout << "Altitude: " << data.altitude << " ft\n";

    return 0;
}