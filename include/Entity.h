//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_ENTITY_H
#define SFML_GAME_ENTITY_H

#include "SFML\Graphics.hpp"
class Entity
{
protected:
    struct Positions
    {
        float x;
        float y;
        int width;
        int height;
        float xCollision;
        float yCollision;
        int collisionWidth;
        int collisionHeight;
    };

public:
    Positions positions;
    Positions oldPositions;
    Entity();
    ~Entity();
    virtual void draw() = 0;
    virtual void update(const float dt)=0;
    virtual void input(sf::Event *event)=0;
};

#endif //SFML_GAME_ENTITY_H
