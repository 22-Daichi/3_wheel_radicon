#include "Machine/OutputModules.hpp"

using Machine::Comptime::AssignedMap;
using Machine::DataStructure::Output;

Machine::OutputModules::OutputModules()
  : motorA{MotorDriver{AssignedMap::PIN_ID_MOTOR_1_A,
                       AssignedMap::PIN_ID_MOTOR_2_A,
                       AssignedMap::PIN_ID_MOTOR_PWM_A,
                       AssignedMap::CHANNEL_ID_MOTOR_A}}
  , motorB{MotorDriver{AssignedMap::PIN_ID_MOTOR_1_B,
                       AssignedMap::PIN_ID_MOTOR_2_B,
                       AssignedMap::PIN_ID_MOTOR_PWM_B,
                       AssignedMap::CHANNEL_ID_MOTOR_B}}
  , motorC{MotorDriver{AssignedMap::PIN_ID_MOTOR_1_C,
                       AssignedMap::PIN_ID_MOTOR_2_C,
                       AssignedMap::PIN_ID_MOTOR_PWM_C,
                       AssignedMap::CHANNEL_ID_MOTOR_C}} {}

Machine::OutputModules::OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC)
  : motorA{motorA}
  , motorB{motorB}
  , motorC{motorC} {}

auto Machine::OutputModules::setup() -> void {
    motorA.setup();
    motorB.setup();
    motorC.setup();
}
auto Machine::OutputModules::write(Output output) -> void {
    motorA.drive(output.motorA);
    motorB.drive(output.motorB);
    motorC.drive(output.motorC);
}
