#pragma once
#include "../flight/FlightData.hpp"

class SimulatedSensor {
    public:
        SimulatedSensor();
        FlightData read();

    private:
        double altitude_;
        double airspeed_;
        double pitch_;
        double roll_;
        double temperature_;
};
