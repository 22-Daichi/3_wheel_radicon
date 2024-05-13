#include <Ps3Controller.h>
#include <hal/gpio_types.h>
#include <hal/ledc_types.h>

#include "InputModules.hpp"
#include "Model.hpp"
#include "Motordrive.hpp"
#include "OutputModules.hpp"

using Machine::InputFrame;

constexpr auto PIN_ID_MOTOR_1_A = GPIO_NUM_13;
constexpr auto PIN_ID_MOTOR_2_A = GPIO_NUM_12;
constexpr auto PIN_ID_MOTOR_PWM_A = GPIO_NUM_14;
constexpr auto CHANNEL_ID_MOTOR_A = LEDC_CHANNEL_0;
constexpr auto PIN_ID_MOTOR_1_B = GPIO_NUM_27;
constexpr auto PIN_ID_MOTOR_2_B = GPIO_NUM_26;
constexpr auto PIN_ID_MOTOR_PWM_B = GPIO_NUM_25;
constexpr auto CHANNEL_ID_MOTOR_B = LEDC_CHANNEL_1;
constexpr auto PIN_ID_MOTOR_1_C = GPIO_NUM_3;
constexpr auto PIN_ID_MOTOR_2_C = GPIO_NUM_21;
constexpr auto PIN_ID_MOTOR_PWM_C = GPIO_NUM_5;
constexpr auto CHANNEL_ID_MOTOR_C = LEDC_CHANNEL_2;

auto inputModules = Machine::InputModules{};
auto outputModules =
  Machine::OutputModules{Motordrive{PIN_ID_MOTOR_1_A, PIN_ID_MOTOR_2_A, PIN_ID_MOTOR_PWM_A, CHANNEL_ID_MOTOR_A},
                         Motordrive{PIN_ID_MOTOR_1_B, PIN_ID_MOTOR_2_B, PIN_ID_MOTOR_PWM_B, CHANNEL_ID_MOTOR_B},
                         Motordrive{PIN_ID_MOTOR_1_C, PIN_ID_MOTOR_2_C, PIN_ID_MOTOR_PWM_C, CHANNEL_ID_MOTOR_C}};
auto model = Machine::Logic::Model{};

void setup() {
    model.init();
    inputModules.begin();
    outputModules.setup();
}

void loop() {
    auto input = inputModules.read();
    auto output = model.update(input);
    outputModules.write(output);
}
