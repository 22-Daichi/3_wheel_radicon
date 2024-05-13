#include "Machine/OutputModules.hpp"

Machine::OutputModules::OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC)
  : motorA{motorA}
  , motorB{motorB}
  , motorC{motorC} {}

auto Machine::OutputModules::setup() -> void {
    motorA.setup();
    motorB.setup();
    motorC.setup();
}
auto Machine::OutputModules::write(OutputFrame output) -> void {
    motorA.drive(output.motorA);
    motorB.drive(output.motorB);
    motorC.drive(output.motorC);
}
