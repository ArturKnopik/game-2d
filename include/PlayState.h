//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_PLAYSTATE_H
#define SFML_GAME_PLAYSTATE_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Button.h"


class PlayState : public GameState
{
private:
    std::vector <Button*> gameButtons;
    sf::Event event;

public:
    ~PlayState();
    void draw(const float dt);
    void update(const float dt);
    void input();
    PlayState(std::shared_ptr<Game> game);

};


#endif //SFML_GAME_PLAYSTATE_H
