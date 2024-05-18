#include "Machine/OutputModules.hpp"

using Machine::Comptime::AssignedFeatures;
using Machine::DataStructure::Output;

Machine::OutputModules::OutputModules()
  : motorA{MotorDriver{AssignedFeatures::PIN_ID_MOTOR_1_A,
                       AssignedFeatures::PIN_ID_MOTOR_2_A,
                       AssignedFeatures::PIN_ID_MOTOR_PWM_A,
                       AssignedFeatures::CHANNEL_ID_MOTOR_A}}
  , motorB{MotorDriver{AssignedFeatures::PIN_ID_MOTOR_1_B,
                       AssignedFeatures::PIN_ID_MOTOR_2_B,
                       AssignedFeatures::PIN_ID_MOTOR_PWM_B,
                       AssignedFeatures::CHANNEL_ID_MOTOR_B}}
  , motorC{MotorDriver{AssignedFeatures::PIN_ID_MOTOR_1_C,
                       AssignedFeatures::PIN_ID_MOTOR_2_C,
                       AssignedFeatures::PIN_ID_MOTOR_PWM_C,
                       AssignedFeatures::CHANNEL_ID_MOTOR_C}} {}

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
