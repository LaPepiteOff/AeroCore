cmake_minimum_required(VERSION 3.20)
project(AeroCore
    LANGUAGES CXX
    VERSION 0.1.0
)

#C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_library(aerocore_core
    src/flight/FlightComputer.cpp
    src/sensors/SimulatedImu.cpp
    src/sensors/SimulatedBarometer.cpp
    src/sensors/SimulatedAirspeed.cpp
)

add_executable(
    aerocore
    src/main.cpp
)
target_link_libraries(aerocore PRIVATE aerocore_core)

enable_testing()
add_executable(
    aerocore_tests
    tests/FlightComputerTests.cpp
)
target_link_libraries(aerocore_tests PRIVATE aerocore_core)
add_test(NAME FlightComputerTests COMMAND aerocore_tests)