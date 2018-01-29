//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_GAMESTATE_H
#define SFML_GAME_GAMESTATE_H


#include "Game.h"


class GameState {
public:

    std::shared_ptr<Game> game;

    virtual void draw() = 0;

    virtual void update(const float dt) = 0;

    virtual void input() = 0;

    ~GameState();
};


#endif //SFML_GAME_GAMESTATE_H
