#pragma once

#include <Ps3Controller.h>

#include "Machine/InputFrame.hpp"

namespace Machine {

class InputModules {
private:
    Ps3Controller controller;

public:
    InputModules() = default;

    auto setup() -> bool;
    auto read() -> InputFrame;
};

}
