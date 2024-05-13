#pragma once

#include <Ps3Controller.h>

#include "InputFrame.hpp"

namespace Machine {

class InputModules {
private:
    Ps3Controller controller;

public:
    auto begin() -> bool {
        constexpr std::array<char, 18> ADDRESS = {"9c:9c:1f:d0:04:be"};
        return controller.begin(ADDRESS.data());
    }
    auto read() -> InputFrame {
        InputFrame frame;
        frame.controller = controller.data;
        return frame;
    }
};

}
