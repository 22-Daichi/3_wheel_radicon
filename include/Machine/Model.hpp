#pragma once

#include "Machine/Comptime/DesignedParameters.hpp"
#include "Machine/DataStructure.hpp"
#include "Machine/Model/InputModules.hpp"
#include "Machine/Model/MotorDriver.hpp"
#include "Machine/Model/OutputModules.hpp"

namespace Machine::Model {

auto initialState() -> DataStructure::State;

auto update(const DataStructure::State &,
            const DataStructure::Input &) -> std::pair<DataStructure::State, DataStructure::Output>;

}
