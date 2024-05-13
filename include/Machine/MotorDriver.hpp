#pragma once

#include <esp32-hal-gpio.h>
#include <esp32-hal-ledc.h>

class MotorDriver {
private:
    int pinId1;
    int pinId2;
    int pinIdPwm;
    int channelId;

public:
    MotorDriver(int pinId1, int pinId2, int pinIdPwm, int channelId)
      : pinId1(pinId1)
      , pinId2(pinId2)
      , pinIdPwm(pinIdPwm)
      , channelId(channelId) {}

    auto setup() -> void {
        pinMode(pinId1, OUTPUT);
        pinMode(pinId2, OUTPUT);
        ledcAttachPin(pinIdPwm, channelId);
        ledcSetup(channelId, 12800, 8);
        stop();
    }
    auto drive(int pwmvalue) -> void {
        if (pwmvalue > 0) {
            digitalWrite(pinId1, 1);
            digitalWrite(pinId2, 0);
            ledcWrite(channelId, pwmvalue);
        } else if (pwmvalue < 0) {
            digitalWrite(pinId1, 0);
            digitalWrite(pinId2, 1);
            ledcWrite(channelId, -pwmvalue);
        } else {
            digitalWrite(pinId1, 1);
            digitalWrite(pinId2, 1);
            ledcWrite(channelId, 255);
        }
    }
    auto stop() -> void {
        digitalWrite(pinId1, 0);
        digitalWrite(pinId2, 0);
        ledcWrite(channelId, 0);
    }
};