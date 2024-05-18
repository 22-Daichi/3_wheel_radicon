#pragma once

#include <cstdint>

namespace Machine::Comptime {

class AssignedMap {
public:
    AssignedMap() = delete;

    inline static constexpr uint8_t PIN_ID_MOTOR_1_A = 13;
    inline static constexpr uint8_t PIN_ID_MOTOR_2_A = 12;
    inline static constexpr uint8_t PIN_ID_MOTOR_PWM_A = 14;
    inline static constexpr uint8_t CHANNEL_ID_MOTOR_A = 0;
    inline static constexpr uint8_t PIN_ID_MOTOR_1_B = 27;
    inline static constexpr uint8_t PIN_ID_MOTOR_2_B = 26;
    inline static constexpr uint8_t PIN_ID_MOTOR_PWM_B = 25;
    inline static constexpr uint8_t CHANNEL_ID_MOTOR_B = 1;
    inline static constexpr uint8_t PIN_ID_MOTOR_1_C = 3;
    inline static constexpr uint8_t PIN_ID_MOTOR_2_C = 21;
    inline static constexpr uint8_t PIN_ID_MOTOR_PWM_C = 5;
    inline static constexpr uint8_t CHANNEL_ID_MOTOR_C = 2;
};

}
