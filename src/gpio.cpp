//
// Created by Sebastian Ratz on 24.02.18.
//

#include "../include/gpio.h"
#include <fstream>

namespace raspico {

    Gpio::Gpio(int pin_num) {
        pin_number_ = pin_num;
        pin_name_.append(std::to_string(pin_number_));
        export_pin();
    }

    Gpio::~Gpio() {
        set_value(false);
        set_direction(false);
        unexport_pin();
    }

    void Gpio::write_to_file(std::string filename, std::string content) {
        std::string file_path = base_dir_ + filename;
        std::ofstream file(file_path.c_str());
        if (file.is_open()) {
            file << content;
            file.close();
        }
        else {
            std::string msg = "Failed to open gpio file: ";
            msg.append(file_path);
            std::cerr << msg << std::endl;
        }
    }

    std::string Gpio::read_from_file(std::string filename) const {
        std::string file_path = base_dir_ + filename;
        std::ifstream file(file_path.c_str());

        std::string output;
        if (file.is_open()) {
            std::getline(file, output);
            file.close();
        }
        else {
            std::string msg = "Failed to open gpio_ file: ";
            msg.append(file_path);
            std::cerr << msg << std::endl;
        }
        return output;
    }

    void Gpio::export_pin() {
        write_to_file("export", std::to_string(pin_number_));
    }

    void Gpio::unexport_pin() {
        write_to_file("unexport", std::to_string(pin_number_));
    }

    void Gpio::set_direction(bool out) {
        std::string filename = pin_name_;
        filename.append("/direction");

        if(out) {
            write_to_file(filename, "out");
        }
        else {
            write_to_file(filename, "in");
        }
    }

    void Gpio::set_value(bool value) {
        std::string filename = pin_name_;
        filename.append("/value");
        write_to_file(filename, std::to_string((int)value));
    }

    int Gpio::read_value() const {
        std::string filename = pin_name_;
        filename.append("/value");
        const std::string content = read_from_file(filename);
        const int value = std::atoi(content.c_str());

        if (value != 0 && value != 1) {
            std::cerr << "Unknown GPIO State";
        }

        return value;
    }
} // namespace raspico

