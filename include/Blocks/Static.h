//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_STATIC_H
#define SFML_GAME_STATIC_H

#include "Blocks/Entity.h"

enum siteOfPicture
{
    NW=0,
    N=1,
    NE=2,
    W=3,
    C=4,
    E=5,
    SW=6,
    S=7,
    SE=8
};
enum AnimatedEnum
{
    CAN_BE_ANIMATED=0,
    CAN_NOT_BE_ANIMATED=1
};

class Static :
        public Entity
{
private:

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    SpriteData spriteData;
public:
    Static()=delete;
    Static(float cX,float cY, int cWidth, int cHeight);
};




#endif //SFML_GAME_STATIC_H
