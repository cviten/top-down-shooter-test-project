//
// Created by cviten on 11/23/22.
//

#ifndef TOP_DOWN_SHOOTER_INPUTMANAGER_H
#define TOP_DOWN_SHOOTER_INPUTMANAGER_H

#include <memory>

#include "Input.h"

namespace sf
{
    class Event;
    class Window;
}

class InputManager {
    std::shared_ptr<sf::Window> window;

    Input::InputActions actions;
    Input::InputAxes axes;

    void readPressedKeys();
    void processKeyboardInput(const sf::Event& event);

    void clearInput();
    void finishInput();

    void processEvent(const sf::Event& event);
public:
    const Input::InputActions& getActions() const;

    void setWindow(const std::shared_ptr<sf::Window>& window);

    const Input::InputAxes& getAxes() const;

    void processEvents();



};


#endif //TOP_DOWN_SHOOTER_INPUTMANAGER_H
