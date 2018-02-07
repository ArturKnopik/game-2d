//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_MENUSTATE_H
#define SFML_GAME_MENUSTATE_H


#include "Buttoms/BasicButton.h"
#include "Game.h"
#include <iostream>
#include "GameState.h"
#include "PlayState.h"
#include "Buttoms/BasicButton.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"
class MenuState : public GameState
{
private:
    short menuSwitch=1;

    sf::Font font;
    sf::Text menuText;


public:
    MenuState(std::shared_ptr<Game> game);

    void draw();
    void update(const float dt);
    void input();
private:
    sf::View view;
    void loadgame();
    std::vector <Button*> menuButtonElements;
};


#endif //SFML_GAME_MENUSTATE_H
