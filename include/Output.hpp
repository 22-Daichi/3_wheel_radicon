#pragma once

// 車輪の配置とAの正の向き
// +-------------+
// |  C ----- B  |
// |    \   /    |
// |      A      |
// |     --->    |
// +-------------+
// ※B, Cの正の向きはそれぞれAの正の向きを±120度ずらしたもの

struct Output {
    int motorA;
    int motorB;
    int motorC;
};
