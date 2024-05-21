#include <Arduino.h>
#include <Ps3Controller.h>

#include "InputToOutput.hpp"
#include "MotorDriver.hpp"

const int motorA1 = 12; // IN1
const int motorA2 = 13; // IN2
const int motorAp = 14; // PWM
const int pwmch_A = 0;  // PWMチャンネル

const int motorB1 = 26; // IN1
const int motorB2 = 27; // IN2
const int motorBp = 25; // PWM
const int pwmch_B = 1;  // PWMチャンネル

const int motorC1 = 21; // IN1
const int motorC2 = 3;  // IN2
const int motorCp = 5;  // PWM
const int pwmch_C = 2;  // PWMチャンネル

MotorDrive motorA{motorA1, motorA2, motorAp, pwmch_A};
MotorDrive motorB{motorB1, motorB2, motorBp, pwmch_B};
MotorDrive motorC{motorC1, motorC2, motorCp, pwmch_C};

void setup() {
    // Ps3コントローラとの通信を開始
    Ps3.begin("9c:9c:1f:d0:04:be");
    // 各モータについて、最初に一回だけ行う処理を実行
    motorA.setup();
    motorB.setup();
    motorC.setup();
    // 各モータを停止 (念のため暴走防止)
    motorA.DRIVE(0);
    motorB.DRIVE(0);
    motorC.DRIVE(0);
}

void loop() {
    // コントローラからの入力を取得
    Input input = getInput();
    // 入力を元にモータへの出力を計算
    Output output = inputToOutput(input);
    // モータへの出力を反映
    motorA.DRIVE(output.motorA);
    motorB.DRIVE(output.motorB);
    motorC.DRIVE(output.motorC);
    // 10ms待機
    delay(10);
}
