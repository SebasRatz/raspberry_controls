//
// Created by Sebastian on 05.08.18.
//

#include <iostream>

#include "include/motor.h"

int main() {
    std::cout << "hello world";

    raspico::Motor motor(13, 19, 26);
    motor.enable();
    motor.forward();

    std::cin.get();
    return 0;
}