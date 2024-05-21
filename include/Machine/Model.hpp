#pragma once

#include "Machine/Comptime/DesignedParameters.hpp"
#include "Machine/DataStructure.hpp"

namespace Machine {

class Model {
private:
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