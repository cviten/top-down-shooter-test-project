//
// Created by cviten on 11/12/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMEMANAGER_H
#define TOP_DOWN_SHOOTER_GAMEMANAGER_H

#include "Frontend/Graphics/Graphics.h"
#include "Frontend/Input/InputManager.h"
#include "Backend/GameLogic/GameWorld.h"

namespace sf {
    class RenderWindow;
};

class GameManager {
    Graphics graphics;
    GameWorld gameWorld;
    InputManager inputManager;


    // Not mandatory but for optimization
//    std::shared_ptr<sf::RenderWindow> window;
//    void close(const std::shared_ptr<sf::RenderWindow>& window);
public:
    GameManager();
    void readInput();

    // ---
    void gameLoop();
};


#endif //TOP_DOWN_SHOOTER_GAMEMANAGER_H
