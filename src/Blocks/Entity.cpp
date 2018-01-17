//
// Created by Streaming on 2017-12-13.
//
#include "Blocks/Entity.h"
#include <iostream>


Entity::~Entity()
{
}

Entity::Entity(const float cX, const float cY, const int cWidth, const int cHeight)
{
    positions.x=cX;
    positions.y=cY;
    positions.width=cWidth;
    positions.height=cHeight;
    positions.xCollision=cX;
    positions.yCollsion=cX;
    positions.xCollsionWidth=cWidth;
    positions.yCollsionHeight=cHeight;
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