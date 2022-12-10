//
// Created by cviten on 11/23/22.
//

#ifndef TOP_DOWN_SHOOTER_INPUTMANAGER_H
#define TOP_DOWN_SHOOTER_INPUTMANAGER_H

#include <memory>

#include "Core/Input.h"

namespace sf
{
    class Event;
    class Window;
}

class InputManager {
    std::shared_ptr<sf::Window> window;

    Input::Inputs inputs;

    void readPressedKeys();
    void readMousePosition();
    void processKeyboardInput(const sf::Event& event);
    void processMouseButtonInput(const sf::Event& event);

    void clearInput();
    void finishInput();

    void processEvent(const sf::Event& event);
public:
    void setWindow(const std::shared_ptr<sf::Window>& window);

    const Input::Inputs& getInputs() const;

    void processEvents();



};


#endif //TOP_DOWN_SHOOTER_INPUTMANAGER_H
