//
// Created by Sebastian Ratz on 24.02.18.
//

#ifndef RASPBERRY_CONTROLS_GPIO_HPP
#define RASPBERRY_CONTROLS_GPIO_HPP
#include <iostream>

namespace raspico {
    class Gpio {
    public:
        explicit Gpio(int pin_number);
        ~Gpio();
        Gpio(const Gpio& other) = delete;
        Gpio(Gpio&& other) = default;

        /*!
         * Set gpio direction to OUT or IN
         * @param out true for OUT, false for IN
         */
        void set_direction(bool out);

        /*!
         * Set current to HIGH or LOW
         * @param value true for HIGH, false for LOW
         */
        void set_value(bool value);

        int read_value() const;
    private:
        int pin_number_=-1;
        std::string pin_name_ = "gpio";
        std::string base_dir_ ="/sys/class/gpio/";

        void write_to_file(std::string filename, std::string content);
        std::string read_from_file(std::string filename) const;

        void export_pin();
        void unexport_pin();


    };
} // namespace raspico
#endif //RASPBERRY_CONTROLS_GPIO_HPP
