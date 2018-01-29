//
// Created by Streaming on 2017-12-13.
//
#include "Blocks/Entity.h"
#include <iostream>


Entity::~Entity() {
}

Entity::Entity(float cX, float cY, int cWidth, int cHeight)
        : positions(Positions(cX, cY)) {
    this->size.width = cWidth;
    this->size.height = cHeight;
    this->collisonParameters.xCollision = cX;
    this->collisonParameters.yCollision = cX;
    this->collisonParameters.xCollisionWidth = cWidth;
    this->collisonParameters.yCollisionHeight = cHeight;

}


Positions &Positions::operator=(const Positions &right) {
    if (&right != this) {
        x = right.x;
        y = right.y;
    }
    return *this;
}


bool Entity::getCollsionStatus() {
    if (collisonParameters.collisionStatus == IS_COLLIDET) {
        return true;
    } else {
        return false;
    }
}

bool Entity::isCollisionAble() {
    if (collisonParameters.collisionAble == CAN_BE_COLLIDET) {
        return true;
    } else return false;
}

void Entity::setCollisionAble(CollisionEnum newCollisionAble) {
    this->collisonParameters.collisionAble = newCollisionAble;
}

void Entity::setCollisionStatus(IsCollidet newCollisionStatus) {
    this->collisonParameters.collisionStatus = newCollisionStatus;
}

void Entity::setEntityID(int i) {
    this->id = i;
}

int Entity::getEntityID() {
    return id;
}

TypeOfEntity Entity::getTypeOfEntity() {
    return typeOfEntity;
}

void Entity::setTypeOfEntity(TypeOfEntity typeOfEntity) {
    Entity::typeOfEntity = typeOfEntity;
}

Positions Entity::getPositions() {
    return positions;
}

void Entity::setPositions(Positions positions) {
    this->positions = positions;
}

SpriteData &SpriteData::operator=(const SpriteData &right) {
    if (&right != this) {
        timeToNextFrame = right.timeToNextFrame;
        currentTime = right.currentTime;
        numbersOfFrame = right.numbersOfFrame;
        currentFrame = right.currentFrame;
        spriteWidth = right.spriteWidth;
        spriteHeight = right.spriteHeight;
        spriteOffsetX = right.spriteOffsetX;
        spriteOffsetY = right.spriteOffsetY;
    }
    return *this;
}


 Size Entity::getSize() {
    return size;
}

void Entity::setSize( Size size) {
    Entity::size = size;
}


