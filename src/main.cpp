#include <iostream>
#include "sensors/SimulatedImu.hpp"
#include "flight/FlightComputer.hpp"
#include "sensors/SimulatedBarometer.hpp"
#include "sensors/SimulatedAirspeed.hpp"

int main()
{
    std::cout << "AeroCore Flight Computer \n";
    std::cout << "System status : Online\n";

    SimulatedImu imu;
    FlightComputer flightComputer;
    SimulatedBarometer barometer;
    SimulatedAirspeed airspeed;

    for (int i = 0; i < 10; ++i) {
        ImuData imuData = imu.read();
        flightComputer.updateFromImu(imuData);

        BarometerData barometerData = barometer.read();
        flightComputer.updateFromBarometer(barometerData);

        AirspeedData airspeedData = airspeed.read();
        flightComputer.updateFromAirspeed(airspeedData);

        const FlightData& flightData = flightComputer.getFlightData();

        std::cout << "Altitude: " << flightData.altitude << " ft\n";
        std::cout << "Airspeed: " << flightData.airspeed << " kt\n";
        std::cout << "Pitch: " << flightData.pitch << " deg\n";
        std::cout << "Roll: " << flightData.roll << " deg\n";
        std::cout << "Temperature: " << flightData.temperature << " C\n";
        std::cout << "-------------------------\n";
    }

    return 0;
}