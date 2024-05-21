#pragma once

#include "Machine/Comptime.hpp"
#include "Machine/DataStructure/Output.hpp"
#include "Machine/Model/MotorDriver.hpp"

namespace Machine::Model {

class OutputModules {
private:
    MotorDriver motorA;
    MotorDriver motorB;
    MotorDriver motorC;

public:
    OutputModules();
    OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC);

    auto setup() -> void;
    auto write(DataStructure::Output output) -> void;
};

}
