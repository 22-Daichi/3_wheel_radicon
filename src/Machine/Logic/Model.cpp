#include "Machine/Logic/Model.hpp"

auto Machine::Logic::Model::init() -> void {
    machineAngle = 0;
}

auto Machine::Logic::Model::update(Machine::InputFrame in) -> Machine::OutputFrame {
    const auto &c = in.controller;

    if (c.button.cross) {
        return {0, 0, 0};
    }

    int x = c.analog.stick.lx * -1.9;
    int y = c.analog.stick.ly * -1.9;
    int omega = c.button.circle ? 200 : c.button.square ? -200 : 0;

    Machine::OutputFrame out;
    out.motorA = x * cos(-machineAngle) * y * sin(-machineAngle) + omega;
    out.motorB = x * cos(-machineAngle + 2 * M_PI / 3) + y * sin(-machineAngle + 2 * M_PI / 3) + omega;
    out.motorC = x * cos(-machineAngle - 2 * M_PI / 3) + y * sin(-machineAngle - 2 * M_PI / 3) + omega;
    return out;
}
