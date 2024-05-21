#include <Arduino.h>

#include "Machine.hpp"

auto inputModules = Machine::Model::InputModules{};
auto outputModules = Machine::Model::OutputModules{};

auto state = Machine::DataStructure::State{};

void setup() {
    inputModules.setup();
    outputModules.setup();
    state = Machine::Model::initialState();
}

void loop() {
    const auto input = inputModules.read();
    const auto [nextState, output] = Machine::Model::update(state, input);
    state = nextState;
    outputModules.write(output);
    delay(10);
}
