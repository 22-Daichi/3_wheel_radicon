#include <Arduino.h>
#include <Ps3Controller.h>

#include "InputModules.hpp"
#include "Motordrive.hpp"

using Machine::InputFrame;

Machine::InputModules inputModules;

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

Motordrive motorA{motorA1, motorA2, motorAp, pwmch_A};
Motordrive motorB{motorB1, motorB2, motorBp, pwmch_B};
Motordrive motorC{motorC1, motorC2, motorCp, pwmch_C};

int controller_x(InputFrame input) {
    return input.controller.analog.stick.lx * -1.9;
}
int controller_y(InputFrame input) {
    return input.controller.analog.stick.ly * -1.9;
}

int velocityA(InputFrame input) {
    return controller_x(input);
}
int velocityB(InputFrame input) {
    return (-1 * controller_x(input) / 2) + (controller_y(input) * 1.732 / 2);
}
int velocityC(InputFrame input) {
    return (-1 * controller_x(input) / 2) + (-1 * controller_y(input) * 1.732 / 2);
}

void setup() {
    inputModules.begin();
    motorA.setup();
    motorB.setup();
    motorC.setup();
    motorA.DRIVE(0);
    motorB.DRIVE(0);
    motorC.DRIVE(0);
}

void loop() {
    auto input = inputModules.read();
    int v_a = velocityA(input);
    int v_b = velocityB(input);
    int v_c = velocityC(input);

    if (input.controller.button.circle) {
        v_a += 200;
        v_b += 200;
        v_c += 200;
    } else if (input.controller.button.square) {
        v_a -= 200;
        v_b -= 200;
        v_c -= 200;
    } else if (input.controller.button.cross) {
        v_a = 0;
        v_b = 0;
        v_c = 0;
    }
    motorA.DRIVE(v_a);
    motorB.DRIVE(v_b);
    motorC.DRIVE(v_c);
}
