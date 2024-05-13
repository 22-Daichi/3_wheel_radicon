#pragma once

#include "Machine/MotorDriver.hpp"
#include "Machine/OutputFrame.hpp"

namespace Machine {

class OutputModules {
private:
    MotorDriver motorA;
    MotorDriver motorB;
    MotorDriver motorC;

public:
    OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC);

    auto setup() -> void;
    auto write(OutputFrame output) -> void;
};

}
