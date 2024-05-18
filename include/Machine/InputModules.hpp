#pragma once

#include <Ps3Controller.h>

#include "Machine/Logic/Input.hpp"

namespace Machine {

class InputModules {
private:
    Ps3Controller controller;

public:
    InputModules() = default;

    auto setup() -> bool;
    auto read() -> Logic::Input;
};

}
