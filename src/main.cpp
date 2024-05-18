#include <Arduino.h>

#include "Machine/InputModules.hpp"
#include "Machine/Model.hpp"
#include "Machine/OutputModules.hpp"

using Machine::InputModules;
using Machine::Model;
using Machine::OutputModules;

auto inputM = InputModules{};
auto outputM = OutputModules{};
auto model = Model{};

void setup() {
    inputM.setup();
    outputM.setup();
    model.init();
}

void loop() {
    const auto input = inputM.read();
    const auto output = model.update(input);
    outputM.write(output);
}
