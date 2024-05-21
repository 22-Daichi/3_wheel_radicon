#pragma once

// 車輪の配置と正の向き
// +-------------+
// | Aの正の向き |
// |    <----    |
// |      A      |
// |    /   \    |
// |  B ----- C  |
// +-------------+
// ※B, Cの正の向きはそれぞれAの正の向きを±120度ずらしたもの

struct Output {
    int motorA;
    int motorB;
    int motorC;
};
