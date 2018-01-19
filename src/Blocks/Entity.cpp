//
// Created by Streaming on 2017-12-13.
//
#include "Blocks/Entity.h"
#include <iostream>


Entity::~Entity()
{
}

Entity::Entity(float cX, float cY,  int cWidth,  int cHeight)
{
    this->positions.x=cX;
    this->positions.y=cY;
    this->positions.width=cWidth;
    this->positions.height=cHeight;
    this->positions.xCollision=cX;
    this->positions.yCollsion=cX;
    this->positions.xCollsionWidth=cWidth;
    this->positions.yCollsionHeight=cHeight;
}


Positions & Positions::operator =( const Positions & right )
{
    if( & right != this )
    {
        x=right.x;
        y=right.y;
        width=right.width;
        height=right.height;
        xCollision=right.xCollision;
        yCollsion=right.yCollsion;
        xCollsionWidth=right.xCollsionWidth;
        yCollsionHeight=right.yCollsionHeight;
    }
    return * this;
}


bool Entity::isCollsion() {
    return collsion;
}

void Entity::setCollsion(bool collsion) {
    this->collsion = collsion;
}
