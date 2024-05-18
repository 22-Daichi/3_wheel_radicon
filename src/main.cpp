#include <Arduino.h>

#include "Machine/InputModules.hpp"
#include "Machine/Logic/Model.hpp"
#include "Machine/MotorDriver.hpp"
#include "Machine/OutputModules.hpp"

using Machine::InputModules;
using Machine::MotorDriver;
using Machine::OutputModules;
using Machine::Logic::Model;

constexpr uint8_t PIN_ID_MOTOR_1_A = 13;
constexpr uint8_t PIN_ID_MOTOR_2_A = 12;
constexpr uint8_t PIN_ID_MOTOR_PWM_A = 14;
constexpr uint8_t CHANNEL_ID_MOTOR_A = 0;
constexpr uint8_t PIN_ID_MOTOR_1_B = 27;
constexpr uint8_t PIN_ID_MOTOR_2_B = 26;
constexpr uint8_t PIN_ID_MOTOR_PWM_B = 25;
constexpr uint8_t CHANNEL_ID_MOTOR_B = 1;
constexpr uint8_t PIN_ID_MOTOR_1_C = 3;
constexpr uint8_t PIN_ID_MOTOR_2_C = 21;
constexpr uint8_t PIN_ID_MOTOR_PWM_C = 5;
constexpr uint8_t CHANNEL_ID_MOTOR_C = 2;

auto input = InputModules{};
auto output = OutputModules{MotorDriver{PIN_ID_MOTOR_1_A, PIN_ID_MOTOR_2_A, PIN_ID_MOTOR_PWM_A, CHANNEL_ID_MOTOR_A},
                            MotorDriver{PIN_ID_MOTOR_1_B, PIN_ID_MOTOR_2_B, PIN_ID_MOTOR_PWM_B, CHANNEL_ID_MOTOR_B},
                            MotorDriver{PIN_ID_MOTOR_1_C, PIN_ID_MOTOR_2_C, PIN_ID_MOTOR_PWM_C, CHANNEL_ID_MOTOR_C}};
auto model = Model{};

void setup() {
    input.setup();
    output.setup();
    model.init();
}

void loop() {
    const auto i = input.read();
    const auto o = model.update(i);
    output.write(o);
}
