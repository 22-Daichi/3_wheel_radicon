#pragma once

#include "Machine/Logic/Output.hpp"
#include "Machine/MotorDriver.hpp"

namespace Machine {

class OutputModules {
private:
    MotorDriver motorA;
    MotorDriver motorB;
    MotorDriver motorC;

public:
    OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC);

    auto setup() -> void;
    auto write(Logic::Output output) -> void;
};

}
