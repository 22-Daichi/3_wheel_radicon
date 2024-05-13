#pragma once

#include "Machine/InputFrame.hpp"
#include "Machine/OutputFrame.hpp"

namespace Machine {

namespace Logic {

class Model {
private:
    float machineAngle;

public:
    auto init() -> void {
        machineAngle = 0;
    }
    auto update(Machine::InputFrame input) -> Machine::OutputFrame {
        auto &c = input.controller;

        if (c.button.cross) {
            return {0, 0, 0};
        }

        int x = c.analog.stick.lx * -1.9;
        int y = c.analog.stick.ly * -1.9;
        int omega = c.button.circle ? 200 : c.button.square ? -200 : 0;

        Machine::OutputFrame output;
        output.motorA = x * cos(-machineAngle) * y * sin(-machineAngle) + omega;
        output.motorB = x * cos(-machineAngle + 2 * M_PI / 3) + y * sin(-machineAngle + 2 * M_PI / 3) + omega;
        output.motorC = x * cos(-machineAngle - 2 * M_PI / 3) + y * sin(-machineAngle - 2 * M_PI / 3) + omega;
        return output;
    }
};

}

}