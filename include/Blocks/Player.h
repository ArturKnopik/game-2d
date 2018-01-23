//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_PLAYER_H
#define SFML_GAME_PLAYER_H

#include "Blocks/Dynamic.h"


class Player
        :public Dynamic
{
private:
    int idleTime=0; //1000000 = 1s
public:
    Player()=delete;
    Player(float cX, float cY, int cWidth, int cHeight, float cSpeed);
    void draw(std::shared_ptr<sf::RenderWindow> window) override;
    void update(const float dt);
    void input(std::shared_ptr<sf::Event> event);


};


#endif //SFML_GAME_PLAYER_H
