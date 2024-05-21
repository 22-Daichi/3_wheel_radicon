#include <Arduino.h>
#include <Ps3Controller.h>

#include "InputToOutput.hpp"
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

void setup() {
    // PCとの通信を開始
    Serial.begin(115200);
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
