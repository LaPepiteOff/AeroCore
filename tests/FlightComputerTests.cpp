#include <limits>
#include <cassert>
#include <iostream>
#include "../src/flight/FlightComputer.hpp"



int main()
{
    FlightComputer computer;

    //Vérification valeur 250.0kt acceptée
    bool accepted = computer.updateFromAirspeed(AirspeedData{250.0});
    assert(accepted);

    //Vérification valeur -10.0kt refusée
    bool negAirspeedAccepted = computer.updateFromAirspeed(AirspeedData{-10.0});
    assert(!negAirspeedAccepted);

    //Vérification valeur NAN refusée
    double nanValue = std::numeric_limits<double>::quiet_NaN();
    bool nanAccepted = computer.updateFromAirspeed(AirspeedData{nanValue});
    assert(!nanAccepted);

    //Vérification valeur +infini refusée
    double infinityValue = std::numeric_limits<double>::infinity();
    bool infinityAccepted = computer.updateFromAirspeed(AirspeedData{infinityValue});
    assert(!infinityAccepted);

    const FlightData& data = computer.getFlightData();
    assert(data.airspeed == 250.0);

    //TESTS IMU
    
    //Echantillon valide
    ImuData validImu{5.0, 2.0};
    bool valImuData = computer.updateFromImu(validImu);
    assert(valImuData);

    assert(data.pitch == 5.0);
    assert(data.roll == 2.0);

    //Echantillon invalide
    ImuData invalidImu{6.0, 999.0};
    bool invalImuData = computer.updateFromImu(invalidImu);
    assert(!invalImuData);

    assert(data.pitch == 5.0);
    assert(data.roll == 2.0);

    //TESTS BAROMETRE
    
    //Echantillon valide
    BarometerData validBarometer{10000.0, 20.0};
    bool valBarometerData = computer.updateFromBarometer(validBarometer);
    assert(valBarometerData);

    assert(data.altitude == 10000.0);
    assert(data.temperature == 20.0);

    //Echantillon invalide
    BarometerData invalidBarometer{10250.0, -120.0};
    bool invalBarometerData = computer.updateFromBarometer(invalidBarometer);
    assert(!invalBarometerData);

    assert(data.altitude == 10000.0);
    assert(data.temperature == 20.0);
}