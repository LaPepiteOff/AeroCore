#include "SimulatedSensor.hpp"

constexpr double kAltitudeStep = 25.0;
constexpr double kAirspeedStep = 0.5;
constexpr double kPitchStep = 0.2;
constexpr double kRollStep = -0.1;
constexpr double kTemperatureStep = -0.05;

SimulatedSensor::SimulatedSensor() 
    : altitude_(10000.0),
      airspeed_(250.0),
      pitch_(5.0),
      roll_(2.0),
      temperature_(-20.0) 
{
}

FlightData SimulatedSensor::read(){
    FlightData data = { 
        .altitude = altitude_, 
        .airspeed = airspeed_, 
        .pitch = pitch_, 
        .roll = roll_, 
        .temperature = temperature_ 
    };

    altitude_ += kAltitudeStep;
    airspeed_ += kAirspeedStep;
    pitch_ += kPitchStep;
    roll_ += kRollStep;
    temperature_ += kTemperatureStep;

    return data;
}