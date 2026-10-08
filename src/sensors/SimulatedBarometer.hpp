#pragma once 
#include "BarometerData.hpp"

class SimulatedBarometer {
    public:
        SimulatedBarometer();
        BarometerData read();

    private:
        double altitude_;
        double temperature_;
};