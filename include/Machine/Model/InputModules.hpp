#pragma once

#include <Ps3Controller.h>

#include "Machine/Comptime.hpp"
#include "Machine/DataStructure/Input.hpp"

namespace Machine::Model {

class InputModules {
private:
    Ps3Controller controller;

public:
    InputModules() = default;

    auto setup() -> bool;
    auto read() -> DataStructure::Input;
};

}
