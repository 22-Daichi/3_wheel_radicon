#pragma once

#include "MotorDriver.hpp"
#include "OutputFrame.hpp"

namespace Machine {

class OutputModules {
private:
    MotorDriver motorA;
    MotorDriver motorB;
    MotorDriver motorC;

public:
    OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC)
      : motorA(motorA)
      , motorB(motorB)
      , motorC(motorC) {}

    auto setup() -> void {
        motorA.setup();
        motorB.setup();
        motorC.setup();
    }
    auto write(OutputFrame output) -> void {
        motorA.drive(output.motorA);
        motorB.drive(output.motorB);
        motorC.drive(output.motorC);
    }
};

}
