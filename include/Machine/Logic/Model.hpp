#pragma once

#include "Machine/InputFrame.hpp"
#include "Machine/OutputFrame.hpp"

namespace Machine {

namespace Logic {

class Model {
private:
    float machineAngle;

public:
    Model() = default;

    auto init() -> void;
    auto update(Machine::InputFrame in) -> Machine::OutputFrame;
};

}

}