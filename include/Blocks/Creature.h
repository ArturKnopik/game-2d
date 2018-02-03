//
// Created by Streaming on 2018-01-23.
//

#ifndef SFML_GAME_CREATURE_H
#define SFML_GAME_CREATURE_H


#include "Dynamic.h"
enum CreatureStatusVSPlayer
{
    AGGRESIVE,
    PASSIVE
};

class Creature
: public Dynamic
{

public:
    Creature()=delete;
    /// Default Creature constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    /// @param cSpeed - speed of Dynamic entity
    Creature(float cX, float cY, int cWidth, int cHeight, float cSpeed);
};


#endif //SFML_GAME_CREATURE_H
