#pragma once

#include "Machine/InputFrame.hpp"
#include "Machine/OutputFrame.hpp"

namespace Machine {

namespace Logic {

class Model {
private:
    float machineAngle;

public:
    inline static constexpr float ANGLE_OFFSET_A = M_PI;
    inline static constexpr float ANGLE_OFFSET_B = -M_PI / 3;
    inline static constexpr float ANGLE_OFFSET_C = M_PI / 3;

    Model() = default;

    auto init() -> void;
    auto update(Machine::InputFrame in) -> Machine::OutputFrame;
};

}

}