//
// Created by cviten on 11/27/22.
//

#ifndef TOP_DOWN_SHOOTER_INPUT_H
#define TOP_DOWN_SHOOTER_INPUT_H

#include "Core.h"
#include "CoreTypes.h"

namespace Input
{
    // Consider remaking them as classes loaded through config
    enum class InputAxis { Move };
    enum class InputPoint { TargetPosition };
    enum class InputAction { Shoot };

    using InputAxes = MappingType<InputAxis, Direction>;
    using InputPoints = MappingType<InputPoint, Point>;
    using InputActions = MappingType<InputAction, bool>;

    struct Inputs
    {
        InputAxes axes;
        InputPoints points;
        InputActions actions;
    };
}

#endif //TOP_DOWN_SHOOTER_INPUT_H
