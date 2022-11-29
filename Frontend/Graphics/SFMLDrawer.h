//
// Created by cviten on 11/12/22.
//

#ifndef TOP_DOWN_SHOOTER_SFMLDRAWER_H
#define TOP_DOWN_SHOOTER_SFMLDRAWER_H

#include <memory>

#include "Core/DrawObject.h"

namespace sf {
    class RenderWindow;
    class RectangleShape;
};



class SFMLDrawer {
    std::shared_ptr<sf::RenderWindow> win;

    void drawRectangle(const DrawObject& obj, DrawSettings::Color color);

    void drawCircle(const DrawObject& obj, DrawSettings::Color color);

public:
    SFMLDrawer(const std::shared_ptr<sf::RenderWindow>& win);

    void changeWindow(const std::shared_ptr<sf::RenderWindow>& win);

    // TODO: Think of better solution than just forwarding parameters
    void drawObject(const DrawObject& obj, DrawSettings::Color color);

    sf::RectangleShape& toWireframe(sf::RectangleShape& sfShape);
};

#endif //TOP_DOWN_SHOOTER_SFMLDRAWER_H
