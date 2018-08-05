//
// Created by Sebastian Ratz on 24.02.18.
//

#ifndef RASPBERRY_CONTROLS_LED_H
#define RASPBERRY_CONTROLS_LED_H

#include "gpio.h"

namespace raspico {
    class Led {
        Gpio gpio_;

    public:
        explicit Led(int pin_num);
        ~Led() = default;
        Led(const Led& other) = delete;
        Led(Led&& other) = default;
        void on();
        void off();
        void set_state(bool value);
        void opposite();
    };
 } // namespace raspico

#endif // RASPBERRY_CONTROLS_LED_H
