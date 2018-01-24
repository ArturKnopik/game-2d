//
// Created by Root on 18.01.2018.
//

#ifndef SFML_GAME_SIMPLEENEMY_H
#define SFML_GAME_SIMPLEENEMY_H



#include "Creature.h"

class Rat
: public Creature
{
private:
    int timeToChangeStateAndDir=5000000;
    int currentTimeToChangeStateAndDir=0;

   // float idleTime; //1000000 = 1s
    void getRandomMovment();
public:
    Rat()=delete;
    Rat(float cX, float cY, int cWidth, int cHeight, float cSpeed);
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void update(const float dt) override;

};


#endif //SFML_GAME_SIMPLEENEMY_H
