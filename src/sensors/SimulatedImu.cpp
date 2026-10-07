#include "SimulatedImu.hpp"

constexpr double kPitchStep = 0.2;
constexpr double kRollStep = -0.1;

SimulatedImu::SimulatedImu() 
    : pitch_(5.0),
      roll_(2.0) 
{
}

ImuData SimulatedImu::read() {
    ImuData data = { 
        .pitch = pitch_, 
        .roll = roll_ 
    };

    pitch_ += kPitchStep;
    roll_ += kRollStep;

    return data;
}