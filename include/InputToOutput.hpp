#pragma once

#include "Input.hpp"
#include "Output.hpp"

// 車輪の配置とAの正の向き
// +-------------+
// |  C ----- B  |
// |    \   /    |
// |      A      |
// |     --->    |
// +-------------+
// ※B, Cの正の向きはそれぞれAの正の向きを±120度ずらしたもの

Output inputToOutput(Input input) {
    // 各車輪のx軸に対する角度 (反時計回りを正とする)
    const float angleOffsetA = 0;             // 0度
    const float angleOffsetB = 2 * PI / 3.0;  // 120度
    const float angleOffsetC = -2 * PI / 3.0; // -120度
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
    // output.motorA: モータAへの出力 (0~255)
    // output.motorB: モータBへの出力 (0~255)
    // output.motorC: モータCへの出力 (0~255)

    /*
        ここを埋めてください。
        ヒント:
            - input.x, input.yから機体を進めたい量と方向を求める
            - その他のinputの値に応じて機体の回転量や特殊な動作を求める
            - 求めた量からoutput.motorA, output.motorB, output.motorCを決める
            - それぞれ代入する
    */

    // 各モータへの出力をreturn
    return output;
}
