#include <iostream>
#include "flight/FlightData.hpp"
#include "sensors/SimulatedSensor.hpp"
#include "sensors/SimulatedImu.hpp"
#include "flight/FlightComputer.hpp"

int main()
{
    std::cout << "AeroCore Flight Computer \n";
    std::cout << "System status : Online\n";

    SimulatedSensor sensor;
    SimulatedImu imu;
    FlightComputer flightComputer;

    for (int i = 0; i < 10; ++i) {
        FlightData data = sensor.read();
        ImuData imuData = imu.read();
        flightComputer.updateFromImu(imuData);
        const FlightData& flightData = flightComputer.getFlightData();
        std::cout << "Altitude: " << data.altitude << " ft\n";
        std::cout << "Airspeed: " << data.airspeed << " kt\n";
        std::cout << "Pitch: " << flightData.pitch << " deg\n";
        std::cout << "Roll: " << flightData.roll << " deg\n";
        std::cout << "Temperature: " << data.temperature << " C\n";
        std::cout << "Imu Pitch: " << imuData.pitch << " deg\n";
        std::cout << "Imu Roll: " << imuData.roll << " deg\n";
        std::cout << "-------------------------\n";
    }

    return 0;
}