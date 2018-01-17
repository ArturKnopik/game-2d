//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_STATIC_H
#define SFML_GAME_STATIC_H

#include "Blocks/Entity.h"
class Static :
        public Entity
{
public:
    Static()=delete;
    Static(float cX,float cY, int cWidth, int cHeight);
};




#endif //SFML_GAME_STATIC_H
