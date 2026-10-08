#include "FlightComputer.hpp"

void FlightComputer::updateFromImu(const ImuData& data) {
    flightData_.pitch = data.pitch;
    flightData_.roll = data.roll;
}

void FlightComputer::updateFromBarometer(const BarometerData& data) {
    flightData_.altitude = data.altitude;
    flightData_.temperature = data.temperature;
}

const FlightData& FlightComputer::getFlightData() const {
    return flightData_;
}