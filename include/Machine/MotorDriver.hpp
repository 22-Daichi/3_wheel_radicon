#pragma once

#include <esp32-hal-gpio.h>
#include <esp32-hal-ledc.h>

namespace Machine {

class MotorDriver {
private:
    uint8_t pinId1;
    uint8_t pinId2;
    uint8_t pinIdPwm;
    uint8_t channelId;

public:
    MotorDriver(uint8_t pinId1, uint8_t pinId2, uint8_t pinIdPwm, uint8_t channelId);

    auto setup() -> void;
    auto drive(int pwmValue) -> void;
    auto stop() -> void;
};

}