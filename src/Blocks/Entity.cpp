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
    this->positions.yCollision=cX;
    this->positions.xCollisionWidth=cWidth;
    this->positions.yCollisionHeight=cHeight;

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
        yCollision=right.yCollision;
        xCollisionWidth=right.xCollisionWidth;
        yCollisionHeight=right.yCollisionHeight;
    }
    return * this;
}


bool Entity::getCollsionStatus()
{
    if(collisionStatus==CAN_BE_COLLIDET)
    {
        return true;
    }
    else return false;
}
bool Entity::isCollisionAble()
{
    if(collisionAble==CAN_BE_COLLIDET)
    {
        return true;
    }
    else return false;
}

void Entity::setCollisionAble(CollisionEnum newCollisionAble)
{
    this->collisionAble = newCollisionAble;
}

void Entity::setCollisionStatus(CollisionEnum newCollisionStatus)
{
    this->collisionStatus = newCollisionStatus;
}

void Entity::setEntityID(int i)
{
    this->id=i;
}

int Entity::getEntityID()
{
    return id;
}