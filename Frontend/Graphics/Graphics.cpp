//
// Created by cviten on 11/13/22.
//

#include <SFML/Graphics/RenderWindow.hpp>

#include "Graphics.h"

std::shared_ptr<sf::RenderWindow> makeDefaultWindow()
{
    return std::make_shared<sf::RenderWindow>(sf::VideoMode(800,600), "Default SFML Window");
}

Graphics::Graphics(std::shared_ptr<sf::RenderWindow> window) : window(window), drawer(window) {
    if(!window) {
        window = makeDefaultWindow();
        drawer.changeWindow(window);
    }
}

Graphics::Graphics() : Graphics(makeDefaultWindow()) {}

const std::shared_ptr<sf::RenderWindow>& Graphics::getWindow() const {
    return window;
}

void Graphics::drawScene() {
    window->clear();
//    test();
    window->display();
}

void Graphics::drawScene(const std::vector<DrawObject>& drawObjects) {
    window->clear();
    for(const auto& obj : drawObjects)
        drawer.drawObject(obj, colorPalette[obj.objectType]);
    window->display();
}

void Graphics::setColorPalette(const DrawSettings::ObjectColorPalette& colorPalette) {
    Graphics::colorPalette = colorPalette;
}
