#include <Arduino.h>
#include <Ps3Controller.h>
#include "Motordrive.hpp"
#include "InputToOutput.hpp"

constexpr int motorAp = 14;
constexpr int motorBp = 25;
constexpr int motorCp = 5;
constexpr int motorA1 = 13;
constexpr int motorA2 = 12;
constexpr int motorB1 = 27; // IN1
constexpr int motorB2 = 26; // IN2
constexpr int motorC1 = 3; // IN1
constexpr int motorC2 = 21; // IN2

constexpr int pwmch_A = 0;
constexpr int pwmch_B = 1;
constexpr int pwmch_C = 2;

Motordrive motorA{motorA1,motorA2,motorAp,pwmch_A};
Motordrive motorB{motorB1,motorB2,motorBp,pwmch_B};
Motordrive motorC{motorC1,motorC2,motorCp,pwmch_C};

void setup() {
    Serial.begin(115200);
    Ps3.begin("9c:9c:1f:d0:04:be");
    motorA.setup();
    motorB.setup();
    motorC.setup();
    motorA.DRIVE(0);
    motorB.DRIVE(0);
    motorC.DRIVE(0);
}

void loop() {
    Output output = inputToOutput(Ps3.data);
    motorA.DRIVE(output.motorA);
    motorB.DRIVE(output.motorB);
    motorC.DRIVE(output.motorC);
}
