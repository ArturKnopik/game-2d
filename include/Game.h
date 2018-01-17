//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_GAME_H
#define SFML_GAME_GAME_H

#include <vector>
#include "SFML/Graphics.hpp"
#include <memory>
#include <utility>
class GameState;

class Game
{
public:
    Game();
    ~Game();


    void pushState(std::shared_ptr<GameState> state);
    void popState();

    std::shared_ptr<GameState> CurrentState();

    void gameLoop();

    std::shared_ptr<sf::RenderWindow> window;


private:
    std::vector<std::shared_ptr<GameState>> states;

};

#endif //SFML_GAME_GAME_H
