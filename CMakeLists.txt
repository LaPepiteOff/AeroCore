cmake_minimum_required(VERSION 3.20)
project(AeroCore
    LANGUAGES CXX
    VERSION 0.1.0
)

#C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    aerocore
    src/main.cpp
    src/sensors/SimulatedSensor.cpp
)