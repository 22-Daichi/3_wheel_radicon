#pragma once

#include "Motordrive.hpp"
#include "OutputFrame.hpp"

namespace Machine {

class OutputModules {
private:
    Motordrive motorA;
    Motordrive motorB;
    Motordrive motorC;

public:
    OutputModules(Motordrive motorA, Motordrive motorB, Motordrive motorC)
      : motorA(motorA)
      , motorB(motorB)
      , motorC(motorC) {}

    auto setup() -> void {
        motorA.setup();
        motorB.setup();
        motorC.setup();
    }
    auto write(OutputFrame output) -> void {
        motorA.DRIVE(output.motorA);
        motorB.DRIVE(output.motorB);
        motorC.DRIVE(output.motorC);
    }
};

}
