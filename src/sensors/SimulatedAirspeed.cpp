#include "SimulatedAirspeed.hpp"

constexpr double kAirspeedStep = 0.5;

SimulatedAirspeed::SimulatedAirspeed()
    : airspeed_(250.0)
{
}

AirspeedData SimulatedAirspeed::read() {
    AirspeedData data = {
        .airspeed = airspeed_
    };

    airspeed_ += kAirspeedStep;

    return data;
}