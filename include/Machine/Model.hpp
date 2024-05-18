#pragma once

#include "Machine/DataStructure.hpp"

namespace Machine {

class Model {
private:
    inline static constexpr float ANGLE_OFFSET_A = M_PI;
    inline static constexpr float ANGLE_OFFSET_B = -M_PI / 3;
    inline static constexpr float ANGLE_OFFSET_C = M_PI / 3;

    DataStructure::State state;

public:
    Model() = default;
    Model(DataStructure::State state);

    auto init() -> void;
    auto update(const DataStructure::Input &) -> DataStructure::Output;
    static auto update(const DataStructure::State &,
                       const DataStructure::Input &) -> std::pair<DataStructure::State, DataStructure::Output>;
};

}