#include "FlightComputer.hpp"
#include <cmath>

bool FlightComputer::updateFromImu(const ImuData& data) {
    if(
        data.pitch < -90 || 
        data.pitch > 90 || 
        !std::isfinite(data.pitch) || 
        data.roll < -180 || 
        data.roll > 180 ||
        !std::isfinite(data.roll)
    ){
        return false;
    }
    flightData_.pitch = data.pitch;
    flightData_.roll = data.roll;
    return true;
}

bool FlightComputer::updateFromBarometer(const BarometerData& data) {
        if(
        data.altitude < -2000 || 
        data.altitude > 60000 || 
        !std::isfinite(data.altitude) || 
        data.temperature < -100 || 
        data.temperature > 60 ||
        !std::isfinite(data.temperature)
    ){
        return false;
    }
    flightData_.altitude = data.altitude;
    flightData_.temperature = data.temperature;
    return true;
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