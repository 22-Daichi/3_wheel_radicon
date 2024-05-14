#pragma once

#include "Ps3Controller.h"

struct Output {
    int motorA;
    int motorB;
    int motorC;
};

Output inputToOutput(ps3_t ps3Data) {
    const float angleOffsetA = 0.0;
    const float angleOffsetB = 2 * M_PI / 3.0;
    const float angleOffsetC = -2 * M_PI / 3.0;

    if (ps3Data.button.cross) {
        return {0, 0, 0};
    }

    int x = ps3Data.analog.stick.lx * -1.9;
    int y = ps3Data.analog.stick.ly * -1.9;
    int omega = 0;
    if (ps3Data.button.circle) {
        omega = 200;
    }
    else if (ps3Data.button.square) {
        omega = -200;
    }

    Output output = {
      x * cos(angleOffsetA) + y * sin(angleOffsetA) + omega,
      x * cos(angleOffsetB) + y * sin(angleOffsetB) + omega,
      x * cos(angleOffsetC) + y * sin(angleOffsetC) + omega,
    };
    return output;
}
