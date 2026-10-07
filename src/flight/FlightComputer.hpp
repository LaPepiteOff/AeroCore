#pragma once
#include "../sensors/ImuData.hpp"
#include "FlightData.hpp"

class FlightComputer {
    public:
        void updateFromImu(const ImuData& data);
        const FlightData& getFlightData() const;

    private: 
        FlightData flightData_{};
};