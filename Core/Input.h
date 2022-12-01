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
    enum class InputPoint { BulletLaunchTarget };
    enum class InputAction { Shoot };

    using InputAxes = std::map<InputAxis, Direction>;
    using InputPoints = std::map<InputPoint, Point>;
    using InputActions = std::map<InputAction, bool>;
}

#endif //TOP_DOWN_SHOOTER_INPUT_H
