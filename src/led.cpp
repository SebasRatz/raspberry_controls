//
// Created by Sebastian Ratz on 24.02.18.
//

#include "led.h"

namespace raspico {
    Led::Led(int pin_num) : gpio_(pin_num) {
        gpio_.set_direction(true);
        gpio_.set_value(false);
    }

    void Led::on() {
        gpio_.set_value(true);
    }

    void Led::off() {
        gpio_.set_value(false);
    }

    void Led::set_state(bool value) {
        gpio_.set_value(value);
    }

    void Led::opposite() {
        int current_value = gpio_.read_value();
        if (current_value == 1) {
            off();
        }
        else {
            on();
        }
    }
} // namespace raspico

