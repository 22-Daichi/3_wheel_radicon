#include <Arduino.h>
#include <Ps3Controller.h>

#include "MotorDriver.hpp"

constexpr int motorAp = 14;
constexpr int motorBp = 25;
constexpr int motorCp = 5;
constexpr int motorA1 = 13;
constexpr int motorA2 = 12;
constexpr int motorB1 = 27; // IN1
constexpr int motorB2 = 26; // IN2
constexpr int motorC1 = 3;  // IN1
constexpr int motorC2 = 21; // IN2

constexpr int pwmch_A = 0;
constexpr int pwmch_B = 1;
constexpr int pwmch_C = 2;

MotorDrive motorA{motorA1, motorA2, motorAp, pwmch_A};
MotorDrive motorB{motorB1, motorB2, motorBp, pwmch_B};
MotorDrive motorC{motorC1, motorC2, motorCp, pwmch_C};

int controller_x() {
    return Ps3.data.analog.stick.lx * -1.9;
}
int controller_y() {
    return Ps3.data.analog.stick.ly * -1.9;
}

int velocityA() {
    return controller_x();
}
int velocityB() {
    return (-1 * controller_x() / 2) + (controller_y() * 1.732 / 2);
}
int velocityC() {
    return (-1 * controller_x() / 2) + (-1 * controller_y() * 1.732 / 2);
}

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
    int v_a = velocityA();
    int v_b = velocityB();
    int v_c = velocityC();

    if (Ps3.data.button.circle) {
        v_a += 200;
        v_b += 200;
        v_c += 200;
    }
    else if (Ps3.data.button.square) {
        v_a -= 200;
        v_b -= 200;
        v_c -= 200;
    }
    else if (Ps3.data.button.cross) {
        v_a = 0;
        v_b = 0;
        v_c = 0;
    }
    motorA.DRIVE(v_a);
    motorB.DRIVE(v_b);
    motorC.DRIVE(v_c);
}
