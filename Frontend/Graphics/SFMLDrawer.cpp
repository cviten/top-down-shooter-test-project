//
// Created by cviten on 11/12/22.
//

#include "SFMLDrawer.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>


inline sf::Vector2<float> toSFMLVector(const Type2D& in) { return {float(in.x), float(in.y)};}
inline sf::Color toSFMLColor(const DrawSettings::Color& in) { return sf::Color{in.red, in.green, in.blue, in.transparent};}


SFMLDrawer::SFMLDrawer(const std::shared_ptr<sf::RenderWindow>& win) : win(win) {}

void SFMLDrawer::changeWindow(const std::shared_ptr<sf::RenderWindow>& win) {
    SFMLDrawer::win = win;
}

sf::RectangleShape& SFMLDrawer::toWireframe(sf::RectangleShape& sfShape) {
    sfShape.setOutlineColor(sfShape.getFillColor());
    sfShape.setOutlineThickness(1);
    sfShape.setFillColor(sf::Color::Transparent);
    return sfShape;
}

void SFMLDrawer::drawObject(const DrawObject& obj, DrawSettings::Color color) {
    switch (obj.shape) {
        case DrawSettings::Rectangle:
            drawRectangle(obj, color);
            break;
        case DrawSettings::Circle:
            drawCircle(obj, color);
            break;
        default:
            ; // Shouldn't be triggered. Insert some kind of default object that shows wrong thing happened
    }
}

void SFMLDrawer::drawRectangle(const DrawObject& obj, DrawSettings::Color color) {
    sf::RectangleShape shape(toSFMLVector(obj.size));
    shape.setPosition(toSFMLVector(obj.position));
    shape.setFillColor(toSFMLColor(color));
    if(obj.isWireFrame) toWireframe(shape);
    win->draw(shape);
}

void SFMLDrawer::drawCircle(const DrawObject& obj, DrawSettings::Color color) {
    sf::CircleShape shape(obj.size.x);
    shape.setPosition(toSFMLVector(obj.position));
    shape.setFillColor(toSFMLColor(color));
    win->draw(shape);
}
