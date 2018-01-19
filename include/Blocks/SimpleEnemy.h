//
// Created by Root on 18.01.2018.
//

#ifndef SFML_GAME_SIMPLEENEMY_H
#define SFML_GAME_SIMPLEENEMY_H


#include "Dynamic.h"

class SimpleEnemy
: public Dynamic
{
private:
    int timeToChangeStateAndDir=5000000;
    int currentTimeToChangeStateAndDir=0;

   // float idleTime; //1000000 = 1s
    void getRandomMovment();
public:
    SimpleEnemy()=delete;
    SimpleEnemy(float cX, float cY, int cWidth, int cHeight, float cSpeed);
    void draw(std::shared_ptr<sf::RenderWindow> window) override;
    void update(const float dt) override;

};


#endif //SFML_GAME_SIMPLEENEMY_H
