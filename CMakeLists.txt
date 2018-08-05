cmake_minimum_required(VERSION 3.6.2)
project(raspberry_controls)

set(CMAKE_CXX_STANDARD 11)

add_library(raspberry_controls
        include/gpio.h src/gpio.cpp
        include/led.h src/led.cpp
        include/motor.h src/motor.cpp
        )

add_executable(raspico main.cpp)
target_link_libraries(raspico raspberry_controls)