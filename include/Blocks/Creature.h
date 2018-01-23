//
// Created by Streaming on 2018-01-23.
//

#ifndef SFML_GAME_CREATURE_H
#define SFML_GAME_CREATURE_H


#include "Dynamic.h"

class Creature
: public Dynamic
{

public:
    Creature()=delete;
    Creature(float cX, float cY, int cWidth, int cHeight, float cSpeed);
};


#endif //SFML_GAME_CREATURE_H
