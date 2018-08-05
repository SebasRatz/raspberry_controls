#ifndef RASPBERRY_CONTROLS_LIBRARY_H
#define RASPBERRY_CONTROLS_LIBRARY_H


namespace raspico {
    class Motor {
    public:
        Motor(int pin_A, int pin_B, int pin_EN);
        ~Motor();
        Motor(const Motor& other) = delete;
        Motor( Motor&& other) = default;

        void enable();
        void forward();
        void backward();

    private:
        int pin_A_;
        int pin_B_;
        int pin_EN_;
    };

} // namespace raspico
#endif