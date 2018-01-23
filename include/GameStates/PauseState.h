//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_PAUSESTATE_H
#define SFML_GAME_PAUSESTATE_H

#include "GameState.h"
//#include "TestEnemy.h"
#include "Blocks/Block.h"
class PauseState :
        public GameState
{
private:
    sf::Event event;
    //TestEnemy * te;
   std::shared_ptr< Block> block;
public:


    PauseState(std::shared_ptr<Game> game);
    ~PauseState();
    void draw();
    void update(const float dt);
    void input();
};
#endif //SFML_GAME_PAUSESTATE_H
