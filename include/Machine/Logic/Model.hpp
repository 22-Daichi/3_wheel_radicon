#pragma once

#include "Machine/Logic/Input.hpp"
#include "Machine/Logic/Output.hpp"

namespace Machine::Logic {

class Model {
private:
    float machineAngle;

public:
    inline static constexpr float ANGLE_OFFSET_A = M_PI;
    inline static constexpr float ANGLE_OFFSET_B = -M_PI / 3;
    inline static constexpr float ANGLE_OFFSET_C = M_PI / 3;

    Model() = default;

    auto init() -> void;
    auto update(Machine::Logic::Input) -> Machine::Logic::Output;
};

}