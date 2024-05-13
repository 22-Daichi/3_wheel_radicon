#pragma once

#include "MotorDrive.hpp"
#include "OutputFrame.hpp"

namespace Machine {

class OutputModules {
private:
    MotorDrive motorA;
    MotorDrive motorB;
    MotorDrive motorC;

public:
    OutputModules(MotorDrive motorA, MotorDrive motorB, MotorDrive motorC)
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
