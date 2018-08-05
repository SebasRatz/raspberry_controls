cmake_minimum_required(VERSION 3.9)
project(raspberry_controls)

set(CMAKE_CXX_STANDARD 11)

add_library(raspberry_controls
        include/Gpio.h src/Gpio.cpp
        include/Led.h src/Led.cpp
        include/motor.h src/motor.cpp
        )

add_executable(raspico main.cpp)
target_link_libraries(raspico raspberry_controls)