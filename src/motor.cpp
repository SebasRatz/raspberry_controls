#include "../include/motor.h"

namespace raspico {

    Motor::Motor(int pin_A, int pin_B, int pin_EN) : pin_A_(pin_A), pin_B_(pin_B), pin_EN_(pin_EN) {
        pin_A_.set_direction(true);
        pin_B_.set_direction(true);
        pin_EN_.set_direction(true);
    }

    void Motor::enable() {
        pin_EN_.set_value(true);
    }

    void Motor::dispable() {
        pin_EN_.set_value(false);
    }

    void Motor::forward() {
        pin_A_.set_value(true);
        pin_B_.set_value(false);
    }

    void Motor::backward() {
        pin_A_.set_value(false);
        pin_B_.set_value(true);
    }
} // namespace raspico
