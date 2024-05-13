#include "Machine/MotorDriver.hpp"

Machine::MotorDriver::MotorDriver(const uint8_t pin1, const uint8_t pin2, const uint8_t pinPwm, const uint8_t channel)
  : pinId1{pin1}
  , pinId2{pin2}
  , pinIdPwm{pinPwm}
  , channelId{channel} {}

auto Machine::MotorDriver::setup() -> void {
    pinMode(pinId1, OUTPUT);
    pinMode(pinId2, OUTPUT);
    ledcAttachPin(pinIdPwm, channelId);
    ledcSetup(channelId, 12800, 8);
    stop();
}
auto Machine::MotorDriver::drive(int pwmValue) -> void {
    if (pwmValue > 0) {
        digitalWrite(pinId1, 1);
        digitalWrite(pinId2, 0);
        ledcWrite(channelId, pwmValue);
    } else if (pwmValue < 0) {
        digitalWrite(pinId1, 0);
        digitalWrite(pinId2, 1);
        ledcWrite(channelId, -pwmValue);
    } else {
        digitalWrite(pinId1, 1);
        digitalWrite(pinId2, 1);
        ledcWrite(channelId, 255);
    }
}
auto Machine::MotorDriver::stop() -> void {
    digitalWrite(pinId1, 0);
    digitalWrite(pinId2, 0);
    ledcWrite(channelId, 0);
}
