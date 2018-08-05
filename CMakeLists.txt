cmake_minimum_required(VERSION 3.6.2)
project(raspberry_controls)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
add_library(raspberry_controls
        include/gpio.h src/gpio.cpp
        include/led.h src/led.cpp
        include/motor.h src/motor.cpp
        )
