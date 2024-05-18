#include "Machine/Logic/Model.hpp"

using Machine::Logic::Input;
using Machine::Logic::Output;

auto Machine::Logic::Model::init() -> void {
    machineAngle = 0;
}
auto Machine::Logic::Model::update(Input input) -> Output {
    const auto &c = input.controller;

    if (c.button.cross) {
        return Output{0, 0, 0};
    }

    const int x = c.analog.stick.lx * 1.9;
    const int y = c.analog.stick.ly * 1.9;
    const int omega = c.button.circle ? 200 : c.button.square ? -200 : 0;

    Output output;
    output.motorA = x * cos(-machineAngle + ANGLE_OFFSET_A) * y * sin(-machineAngle + ANGLE_OFFSET_A) + omega;
    output.motorB = x * cos(-machineAngle + ANGLE_OFFSET_B) + y * sin(-machineAngle + ANGLE_OFFSET_B) + omega;
    output.motorC = x * cos(-machineAngle + ANGLE_OFFSET_C) + y * sin(-machineAngle + ANGLE_OFFSET_C) + omega;
    return output;
}
