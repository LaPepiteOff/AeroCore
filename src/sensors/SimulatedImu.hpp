#pragma once 
#include "ImuData.hpp"

class SimulatedImu {
    public:
        SimulatedImu();
        ImuData read();

    private:
        double pitch_;
        double roll_;
};