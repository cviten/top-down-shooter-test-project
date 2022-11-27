//
// Created by cviten on 11/12/22.
//

#include "GameManager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

GameManager::GameManager() {
//    window = std::make_shared<sf::RenderWindow>();
    using namespace DrawSettings;
    ObjectColorPalette palette;
    palette.insert(std::make_pair(ObjectPaletteType::Player, Colors::Green));
    palette.insert(std::make_pair(ObjectPaletteType::Enemy, Colors::Blue));
    palette.insert(std::make_pair(ObjectPaletteType::Wall, Colors::Yellow));
    graphics.setColorPalette(palette);
}

void GameManager::gameLoop() {
    auto window = graphics.getWindow();

    sf::Clock clock;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        TimeType deltaTime = clock.restart().asSeconds();

        gameWorld.process(deltaTime);

        graphics.drawScene(gameWorld.getDrawObjects());
    }


}

//void GameManager::close(const std::shared_ptr<sf::RenderWindow>& window) {
//    window->close();
//}