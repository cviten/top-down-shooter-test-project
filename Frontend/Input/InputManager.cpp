//
// Created by cviten on 11/23/22.
//

#include "InputManager.h"

#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

const Input::InputActions& InputManager::getActions() const {
    return actions;
}

const Input::InputAxes& InputManager::getAxes() const {
    return axes;
}

void InputManager::processKeyboardInput(const sf::Event& event) {
    switch (event.key.code) {
        case sf::Keyboard::Space:
            actions[Input::InputAction::Shoot] = true;
            break;
        case sf::Keyboard::Escape:
            window->close();
    }


}

void InputManager::finishInput() {
//    axes[Input::InputAxis::Move] = normalize(axes[Input::InputAxis::Move]);
}

void InputManager::clearInput() {
    axes.clear();
    actions.clear();
}

void InputManager::processEvents() {
    if (!window) return;
    clearInput();
    for (sf::Event event; window->pollEvent(event);)
    {
        processEvent(event);
    }
    readPressedKeys();
    finishInput();
}

void InputManager::readPressedKeys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) axes[Input::InputAxis::Move].y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) axes[Input::InputAxis::Move].y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) axes[Input::InputAxis::Move].x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) axes[Input::InputAxis::Move].x += 1;
    axes[Input::InputAxis::Move] = normalize(axes[Input::InputAxis::Move]);
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
        actions[Input::InputAction::Shoot] = true;
        points[Input::InputPoint::BulletLaunchTarget] = Point (event.mouseButton.x, event.mouseButton.y);
    }
}

const Input::InputPoints& InputManager::getPoints() const {
    return points;
}
