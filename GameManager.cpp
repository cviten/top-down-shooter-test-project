//
// Created by cviten on 11/12/22.
//

#include "GameManager.h"
#include "CoreTypes.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

GameManager::GameManager() {
//    window = std::make_shared<sf::RenderWindow>();
    using namespace DrawSettings;
    ObjectColorPalette palette;
    palette.insert(std::make_pair(GameObjectType::Player, Colors::Green));
    palette.insert(std::make_pair(GameObjectType::Enemy, Colors::Blue));
    palette.insert(std::make_pair(GameObjectType::Wall, Colors::Yellow));
    graphics.setColorPalette(palette);
}

void GameManager::gameLoop() {
    auto window = graphics.getWindow();
    window->setFramerateLimit(60);

    inputManager.setWindow(window);

    sf::Clock clock;
    while (window->isOpen())
    {
        inputManager.processEvents();

        gameWorld.setInputAxes(inputManager.getAxes());
        TimeType deltaTime = clock.restart().asSeconds();

        gameWorld.process(deltaTime);

        graphics.drawScene(gameWorld.getDrawObjects());
    }


}
