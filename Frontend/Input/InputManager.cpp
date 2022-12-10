//
// Created by cviten on 11/23/22.
//

#include "InputManager.h"

#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

void InputManager::processKeyboardInput(const sf::Event& event) {
    switch (event.key.code) {
        case sf::Keyboard::Space:
            inputs.actions[Input::InputAction::Shoot] = true;
            break;
        case sf::Keyboard::Escape:
            window->close();
            break;
        default:
            break;
    }


}

void InputManager::finishInput() {
//    axes[Input::InputAxis::Move] = normalize(axes[Input::InputAxis::Move]);
}

void InputManager::clearInput() {
    // TODO: Replace with clearing only values and not whole structures to take advantage of moving vs creating objects every time
    inputs.axes.clear();
    inputs.actions.clear();
}

void InputManager::processEvents() {
    if (!window) return;
    clearInput();
    for (sf::Event event; window->pollEvent(event);)
    {
        processEvent(event);
    }
    readPressedKeys();
    readMousePosition();
    finishInput();
}

void InputManager::readPressedKeys() {
    Vector dir;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir.x += 1;
    inputs.axes[Input::InputAxis::Move] = normalize(dir);
}

void InputManager::setWindow(const std::shared_ptr<sf::Window>& window) {
    InputManager::window = window;
}

void InputManager::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed)
        window->close();
    if (event.type == sf::Event::KeyPressed)
        processKeyboardInput(event);
    if (event.type == sf::Event::MouseButtonPressed)
        processMouseButtonInput(event);

}

void InputManager::processMouseButtonInput(const sf::Event& event) {
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        inputs.actions[Input::InputAction::Shoot] = true;
//        inputs.points[Input::InputPoint::TargetPosition] = Point (event.mouseButton.x, event.mouseButton.y);
    }
}

const Input::Inputs& InputManager::getInputs() const {
    return inputs;
}

void InputManager::readMousePosition() {
    auto mousePosition = sf::Mouse::getPosition(*window);
    inputs.points[Input::InputPoint::TargetPosition] = Point (mousePosition.x, mousePosition.y);
}
