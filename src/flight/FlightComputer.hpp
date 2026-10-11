#pragma once
#include "../sensors/ImuData.hpp"
#include "../sensors/BarometerData.hpp"
#include "../sensors/AirspeedData.hpp"
#include "FlightData.hpp"

class FlightComputer {
    public:
        bool updateFromImu(const ImuData& data);
        bool updateFromBarometer(const BarometerData& data, double deltaTime);
        bool updateFromAirspeed(const AirspeedData& data);
        const FlightData& getFlightData() const;

    private: 
        FlightData flightData_{};
};