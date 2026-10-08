#include "SimulatedBarometer.hpp"

constexpr double kAltitudeStep = 25.0;
constexpr double kTemperatureStep = 0.05;


SimulatedBarometer::SimulatedBarometer() 
    : altitude_(10000.0),
      temperature_(-20.0) 
{
}

BarometerData SimulatedBarometer::read() {
    BarometerData data = { 
        .altitude = altitude_, 
        .temperature = temperature_ 
    };

    altitude_ += kAltitudeStep;
    temperature_ -= kTemperatureStep;

    return data;
}