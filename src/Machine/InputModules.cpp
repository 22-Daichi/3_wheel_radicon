#include "Machine/InputModules.hpp"

using Machine::DataStructure::Input;

auto Machine::InputModules::setup() -> bool {
    constexpr std::array<char, 18> ADDRESS = {"9c:9c:1f:d0:04:be"};
    return controller.begin(ADDRESS.data());
}
auto Machine::InputModules::read() -> Input {
    Input frame;
    frame.controller = controller.data;
    return frame;
}
