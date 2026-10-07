#include "FlightComputer.hpp"

void FlightComputer::updateFromImu(const ImuData& data) {
    flightData_.pitch = data.pitch;
    flightData_.roll = data.roll;
}

const FlightData& FlightComputer::getFlightData() const {
    return flightData_;
}