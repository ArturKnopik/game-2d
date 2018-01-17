//
// Created by Root on 13.01.2018.
//

#include <iostream>
#include "Blocks/Dynamic.h"

Dynamic::Dynamic(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        :Entity(cX, cY, cWidth, cHeight), speed(cSpeed)
{
    if(speed<0)
    {
        speed=speed*-1;
    }
    dir=DOWN;
    status=STOP;
}

void Dynamic::moveUp(float dt)
{

    newPositions.y=positions.y-(speed*dt);
}

void Dynamic::moveDown(float dt)
{
    newPositions.y=positions.y+(speed*dt);
}

void Dynamic::moveLeft(float dt)
{
    newPositions.x=positions.x-(speed*dt);
}

void Dynamic::moveRight(float dt)
{
    newPositions.x=positions.x+(speed*dt);
}

Status Dynamic::getStatus() const
{
    return status;
}

void Dynamic::setStatus(Status status)
{
    Dynamic::status = status;
}

Directory Dynamic::getDirectory() const
{
    return dir;
}

void Dynamic::setDir(Directory dir)
{
    this->dir=dir;
}
