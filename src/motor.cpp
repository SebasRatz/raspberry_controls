#include "../include/motor.h"

#include <iostream>

namespace raspico {

    Motor::Motor(int pin_A, int pin_B, int pin_EN) : pin_A_(pin_A), pin_B_(pin_B), pin_EN_(pin_EN) {
    }

    Motor::~Motor() {

    }

    void Motor::enable() {

    }

    void Motor::forward() {

    }

    void Motor::backward() {

    }
} // namespace raspico
