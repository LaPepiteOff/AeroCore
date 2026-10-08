#include <iostream>
#include "flight/FlightData.hpp"
#include "sensors/SimulatedSensor.hpp"
#include "sensors/SimulatedImu.hpp"
#include "flight/FlightComputer.hpp"
#include "sensors/SimulatedBarometer.hpp"

int main()
{
    std::cout << "AeroCore Flight Computer \n";
    std::cout << "System status : Online\n";

    SimulatedSensor sensor;
    SimulatedImu imu;
    FlightComputer flightComputer;
    SimulatedBarometer barometer;

    for (int i = 0; i < 10; ++i) {
        FlightData data = sensor.read();

        ImuData imuData = imu.read();
        flightComputer.updateFromImu(imuData);

        BarometerData barometerData = barometer.read();
        flightComputer.updateFromBarometer(barometerData);

        const FlightData& flightData = flightComputer.getFlightData();

        std::cout << "Altitude: " << flightData.altitude << " ft\n";
        std::cout << "Airspeed: " << data.airspeed << " kt\n";
        std::cout << "Pitch: " << flightData.pitch << " deg\n";
        std::cout << "Roll: " << flightData.roll << " deg\n";
        std::cout << "Temperature: " << flightData.temperature << " C\n";
        std::cout << "-------------------------\n";
    }

    return 0;
}