#pragma once

#include "Machine/DataStructure/Input.hpp"
#include "Machine/DataStructure/Output.hpp"
#include "Machine/DataStructure/State.hpp"

namespace Machine {

class Model {
private:
    inline static constexpr float ANGLE_OFFSET_A = M_PI;
    inline static constexpr float ANGLE_OFFSET_B = -M_PI / 3;
    inline static constexpr float ANGLE_OFFSET_C = M_PI / 3;

    DataStructure::State state;

public:
    Model() = default;

    auto init() -> void;
    auto update(DataStructure::Input) -> DataStructure::Output;
};

}