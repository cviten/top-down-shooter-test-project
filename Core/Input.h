//
// Created by cviten on 11/27/22.
//

#ifndef TOP_DOWN_SHOOTER_INPUT_H
#define TOP_DOWN_SHOOTER_INPUT_H

#include <map>

#include "core.h"

namespace Input
{
    // Consider remaking them as classes loaded through config
    enum class InputAxis { Move };
    enum class InputAction { Shoot };

    using InputAxes = std::map<InputAxis, Direction>;
    using InputActions = std::map<InputAction, bool>;
}

#endif //TOP_DOWN_SHOOTER_INPUT_H
