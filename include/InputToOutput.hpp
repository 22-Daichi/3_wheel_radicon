#pragma once

#include "Ps3Controller.h"

struct Output {
    int motorA;
    int motorB;
    int motorC;
};

auto inputToOutput(ps3_t ps3Data) -> Output {
    const float angleOffsetA = 0.0;
    const float angleOffsetB = 2 * M_PI / 3.0;
    const float angleOffsetC = -2 * M_PI / 3.0;

    const auto &analog = ps3Data.analog;
    const auto &button = ps3Data.button;

    if (button.cross) {
        return {0, 0, 0};
    }

    int x = analog.stick.lx * -1.9;
    int y = analog.stick.ly * -1.9;
    int omega = 0;
    if (button.circle) {
        omega = 200;
    } else if (button.square) {
        omega = -200;
    }
    return {
      static_cast<int>(x * cos(angleOffsetA) + y * sin(angleOffsetA) + omega),
      static_cast<int>(x * cos(angleOffsetB) + y * sin(angleOffsetB) + omega),
      static_cast<int>(x * cos(angleOffsetC) + y * sin(angleOffsetC) + omega),
    };
}
