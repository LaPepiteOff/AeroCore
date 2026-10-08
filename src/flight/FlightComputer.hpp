#pragma once
#include "../sensors/ImuData.hpp"
#include "../sensors/BarometerData.hpp"
#include "FlightData.hpp"

class FlightComputer {
    public:
        void updateFromImu(const ImuData& data);
        void updateFromBarometer(const BarometerData& data);
        const FlightData& getFlightData() const;

    private: 
        FlightData flightData_{};
};