//
// Created by cviten on 11/13/22.
//

#ifndef TOP_DOWN_SHOOTER_GRAPHICS_H
#define TOP_DOWN_SHOOTER_GRAPHICS_H

#include <vector>
#include <memory>

#include "DrawObject.h"
#include "SFMLDrawer.h"

namespace sf {
    class RenderWindow;
};


class Graphics {
    std::shared_ptr<sf::RenderWindow> window;
    DrawSettings::ObjectColorPalette colorPalette;
    SFMLDrawer drawer;
public:
    const std::shared_ptr<sf::RenderWindow>& getWindow() const;

    void setColorPalette(const DrawSettings::ObjectColorPalette& colorPalette);

public:
    Graphics();

    explicit Graphics(std::shared_ptr<sf::RenderWindow> window);

    void drawScene();
    void drawScene(const std::vector<DrawObject>& drawObjects);
    // Only testing for purposes. Can be changed at any time
//    void test();
};


#endif //TOP_DOWN_SHOOTER_GRAPHICS_H
