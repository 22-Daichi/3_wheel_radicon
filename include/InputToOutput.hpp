#pragma once

#include "Input.hpp"
#include "Output.hpp"

// 車輪の配置と正の向き
// +-------------+
// | Aの正の向き |
// |    <----    |
// |      A      |
// |    /   \    |
// |  B ----- C  |
// +-------------+
// ※B, Cの正の向きはそれぞれAの正の向きを±120度ずらしたもの

Output inputToOutput(Input input) {
    // 車輪の配置から、各車輪のx軸に対する角度は以下の通りになる。(反時計回りを正とする)
    const float angleOffsetA = M_PI;        // 180度
    const float angleOffsetB = -M_PI / 3.0; // -60度
    const float angleOffsetC = M_PI / 3.0;  // 60度
    // 各モータへの出力を決める変数。この中身に適当な値を代入し、最後にreturnする。
    Output output;

    // inputの各値の意味
    // input.x:        コントローラの左スティックのx軸方向の値
    // input.y:        コントローラの左スティックのy軸方向の値
    // input.circle:   コントローラの〇ボタンが押されているかどうか
    // input.square:   コントローラの□ボタンが押されているかどうか
    // input.cross:    コントローラの✕ボタンが押されているかどうか
    // input.triangle: コントローラの△ボタンが押されているかどうか

    // outputの各値の意味
    // output.motorA: モータAへの出力
    // output.motorB: モータBへの出力
    // output.motorC: モータCへの出力

    // x, y: 並進方向に移動させたい量
    int x = input.x;
    int y = input.y;
    // rotation: 旋回させたい量
    int rotation;
    if (input.circle) {
        // 〇ボタンが押されている場合は右回りに旋回
        rotation = 200;
    }
    else if (input.square) {
        // □ボタンが押されている場合は左回りに旋回
        rotation = -200;
    }
    else {
        // それ以外の場合は旋回させない
        rotation = 0;
    }
    // 各モータへの出力を計算
    output.motorA = x * cos(angleOffsetA) + y * sin(angleOffsetA) + rotation;
    output.motorB = x * cos(angleOffsetB) + y * sin(angleOffsetB) + rotation;
    output.motorC = x * cos(angleOffsetC) + y * sin(angleOffsetC) + rotation;
    // ✕ボタンが押されている場合は停止
    if (input.cross) {
        output.motorA = 0;
        output.motorB = 0;
        output.motorC = 0;
    }

    // 各モータへの出力をreturn
    return output;
}
