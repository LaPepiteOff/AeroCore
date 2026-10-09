#pragma once
#include "AirspeedData.hpp"

class SimulatedAirspeed {
    public:
        SimulatedAirspeed();
        AirspeedData read();
    private: 
        double airspeed_;
};