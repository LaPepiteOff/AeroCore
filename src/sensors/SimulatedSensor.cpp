#include "SimulatedSensor.hpp"

FlightData SimulatedSensor::read(){
    FlightData data = { 
        .altitude = 10000.0, 
        .airspeed = 250.0, 
        .pitch = 5.0, 
        .roll = 2.0, 
        .temperature = -20.0 
    };

    return data;
}