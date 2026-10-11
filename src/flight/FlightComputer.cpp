#include "FlightComputer.hpp"
#include <cmath>

void FlightComputer::updateFromImu(const ImuData& data) {
    flightData_.pitch = data.pitch;
    flightData_.roll = data.roll;
}

void FlightComputer::updateFromBarometer(const BarometerData& data) {
    flightData_.altitude = data.altitude;
    flightData_.temperature = data.temperature;
}

bool FlightComputer::updateFromAirspeed(const AirspeedData& data) {
    if(!std::isfinite(data.airspeed) || data.airspeed < 0){
        return false;
    }
    flightData_.airspeed = data.airspeed;
    return true;
}

const FlightData& FlightComputer::getFlightData() const {
    return flightData_;
}