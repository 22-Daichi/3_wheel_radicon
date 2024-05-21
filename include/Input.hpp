#pragma once

#include "Ps3Controller.h"

// コントローラからの入力 (左スティックと右側の4つのボタンのみ)
struct Input {
    int x;         // 左スティックのx軸方向の値 -255~255
    int y;         // 左スティックのy軸方向の値 -255~255
    bool circle;   // 〇ボタンが押されているかどうか
    bool square;   // □ボタンが押されているかどうか
    bool cross;    // ✕ボタンが押されているかどうか
    bool triangle; // △ボタンが押されているかどうか
};

Input getInput() {
    Input in;
    // 左スティックのx軸方向の値を-255~255に変換
    in.x = constrain(map(Ps3.data.analog.stick.lx, -127, 127, -255, 255), -255, 255);
    // 左スティックのy軸方向の値を-255~255に変換
    in.y = constrain(map(Ps3.data.analog.stick.ly, -127, 127, -255, 255), -255, 255);
    in.circle = Ps3.data.button.circle;
    in.square = Ps3.data.button.square;
    in.cross = Ps3.data.button.cross;
    in.triangle = Ps3.data.button.triangle;

    return in;
}
