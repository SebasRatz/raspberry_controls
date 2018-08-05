//
// Created by Sebastian on 05.08.18.
//

#include <iostream>

#include "include/motor.h"

int main() {
    std::cout << "Starting motor" << std::endl;
    raspico::Motor motor(13, 19, 26);

    std::cout << "Run Forward" << std::endl;
    motor.enable();
    motor.forward();

    std::cin.get();
    std::cout << "Disabling motor" << std::endl;
    motor.disable();

    std::cin.get();
    std::cout << "Run backward" << std::endl;
    motor.enable();
    motor.backward();

    std::cin.get();
    motor.disable();
    return 0;
}