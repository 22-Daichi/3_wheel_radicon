#include "Machine/InputModules.hpp"

using Machine::DataStructure::Input;

auto Machine::InputModules::setup() -> bool {
    using Machine::Comptime::PS3_CONTROLLER_ADDRESS;

    return controller.begin(PS3_CONTROLLER_ADDRESS.data());
}
auto Machine::InputModules::read() -> Input {
    Input frame;
    frame.controller = controller.data;
    return frame;
}
