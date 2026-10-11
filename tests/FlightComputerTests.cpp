#include <limits>
#include <cassert>
#include <iostream>
#include "../src/flight/FlightComputer.hpp"



int main()
{
    FlightComputer computer;

    std::cout << "Vérification valeur 250.0kt acceptée :\n";
    bool accepted = computer.updateFromAirspeed(AirspeedData{250.0});
    assert(accepted);

    std::cout << "Vérification valeur -10.0kt refusée :\n";
    bool negAirspeedAccepted = computer.updateFromAirspeed(AirspeedData{-10.0});
    assert(!negAirspeedAccepted);

    std::cout << "Vérification valeur NAN refusée :\n";
    double nanValue = std::numeric_limits<double>::quiet_NaN();
    bool nanAccepted = computer.updateFromAirspeed(AirspeedData{nanValue});
    assert(!nanAccepted);

    std::cout << "Vérification valeur +infini refusée :\n";
    double infinityValue = std::numeric_limits<double>::infinity();
    bool infinityAccepted = computer.updateFromAirspeed(AirspeedData{infinityValue});
    assert(!infinityAccepted);

    const FlightData& data = computer.getFlightData();
    assert(data.airspeed == 250.0);
}