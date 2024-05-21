#include "Machine/Model/OutputModules.hpp"

using namespace Machine::Comptime::AssignedFeatures;
using Machine::DataStructure::Output;

Machine::Model::OutputModules::OutputModules()
  : motorA{MotorDriver{PIN_ID_MOTOR_1_A, PIN_ID_MOTOR_2_A, PIN_ID_MOTOR_PWM_A, CHANNEL_ID_MOTOR_A}}
  , motorB{MotorDriver{PIN_ID_MOTOR_1_B, PIN_ID_MOTOR_2_B, PIN_ID_MOTOR_PWM_B, CHANNEL_ID_MOTOR_B}}
  , motorC{MotorDriver{PIN_ID_MOTOR_1_C, PIN_ID_MOTOR_2_C, PIN_ID_MOTOR_PWM_C, CHANNEL_ID_MOTOR_C}} {}

Machine::Model::OutputModules::OutputModules(MotorDriver motorA, MotorDriver motorB, MotorDriver motorC)
  : motorA{motorA}
  , motorB{motorB}
  , motorC{motorC} {}

auto Machine::Model::OutputModules::setup() -> void {
    motorA.setup();
    motorB.setup();
    motorC.setup();
}
auto Machine::Model::OutputModules::write(Output output) -> void {
    motorA.drive(output.motorA);
    motorB.drive(output.motorB);
    motorC.drive(output.motorC);
}
