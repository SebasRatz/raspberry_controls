#ifndef RASPBERRY_CONTROLS_LIBRARY_H
#define RASPBERRY_CONTROLS_LIBRARY_H

#include "gpio.h"

namespace raspico {
    class Motor {
    public:
        Motor(int pin_A, int pin_B, int pin_EN);
        ~Motor() = default;
        Motor(const Motor& other) = delete;
        Motor( Motor&& other) = default;

        void enable();
        void dispable();
        void forward();
        void backward();

    private:
        Gpio pin_A_;
        Gpio pin_B_;
        Gpio pin_EN_;
    };

} // namespace raspico
#endif