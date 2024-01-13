#include <Arduino.h>
#include <CHN203.h>
#include <SparkFun_TB6612.h>

// Extend the T6621FNG driver class (Motor) with the GenericDriver interface.
// The T6621FNG class can then be used with the CHN203 controller.
class T6621FNG : Motor, public GenericDriver
{
public:
    T6621FNG(uint8_t in1, uint8_t in2, uint8_t pwm, float offset, uint8_t stby)
        : Motor(in1, in2, pwm, offset, stby){};

    inline void drive(float speed) override
    {
        Motor::drive((int)(255 * speed));
    }

    inline void brake() override
    {
        Motor::brake();
    }
};