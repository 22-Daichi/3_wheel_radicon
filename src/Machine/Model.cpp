#include "Machine/Model.hpp"

using Machine::DataStructure::Input;
using Machine::DataStructure::Output;
using Machine::DataStructure::State;

auto Machine::Model::initialState() -> State {
    State state;
    state.machineAngle = 0;
    return state;
}

auto Machine::Model::update(const State &state, const Input &input) -> std::pair<State, Output> {
    using namespace Machine::Comptime::DesignedParameters;

    const auto &c = input.controller;

    if (c.button.cross) {
        return {state, Output{0, 0, 0}};
    }

    const int x = c.analog.stick.lx * 1.9;
    const int y = c.analog.stick.ly * 1.9;
    const int omega = c.button.circle ? 200 : c.button.square ? -200 : 0;

    Output output;
    output.motorA =
      x * cos(-state.machineAngle + ANGLE_OFFSET_A) * y * sin(-state.machineAngle + ANGLE_OFFSET_A) + omega;
    output.motorB =
      x * cos(-state.machineAngle + ANGLE_OFFSET_B) + y * sin(-state.machineAngle + ANGLE_OFFSET_B) + omega;
    output.motorC =
      x * cos(-state.machineAngle + ANGLE_OFFSET_C) + y * sin(-state.machineAngle + ANGLE_OFFSET_C) + omega;
    return {state, output};
}
