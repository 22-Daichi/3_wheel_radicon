#include <Arduino.h>

#include "Machine.hpp"

auto inputM = Machine::Model::InputModules{};
auto outputM = Machine::Model::OutputModules{};
auto state = Machine::DataStructure::State{};

void setup() {
    inputM.setup();
    outputM.setup();
    state = Machine::Model::initialState();
}

void loop() {
    const auto input = inputM.read();
    const auto [s, output] = Machine::Model::update(state, input);
    state = s;
    outputM.write(output);
}
