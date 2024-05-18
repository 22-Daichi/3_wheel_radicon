#pragma once

#include "Ps3Controller.h"

struct Input {
    int x;
    int y;
    bool circle;
    bool square;
    bool cross;
    bool triangle;
};

Input getInput() {
    Input in;
    in.x = Ps3.data.analog.stick.lx * 1.9;
    in.y = Ps3.data.analog.stick.ly * 1.9;
    in.circle = Ps3.data.button.circle;
    in.square = Ps3.data.button.square;
    in.cross = Ps3.data.button.cross;
    in.triangle = Ps3.data.button.triangle;

    return in;
}
