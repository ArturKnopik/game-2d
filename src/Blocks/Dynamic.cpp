//
// Created by Root on 13.01.2018.
//

#include <iostream>
#include "Blocks/Dynamic.h"

Dynamic::Dynamic(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        : Entity(cX, cY, cWidth, cHeight), speed(cSpeed), oldPositions(Positions(getPositions().x, getPositions().y)) {
    setTypeOfEntity(CREATURE);
    setCollisionStatus(IS_COLLIDET);
    texture.setSmooth(true);
    if (speed < 0) {
        speed = speed * -1;
    }
    direction = DOWN;
    status = STOP;
    oldPositions = getPositions();
    sprite.setPosition(getPositions().x, getPositions().y);
}

void Dynamic::moveUp(float dt) {
    oldPositions.y = getPositions().y;
    setPositions(Positions(getPositions().x, getPositions().y - (speed * dt)));
}

void Dynamic::moveDown(float dt) {
    oldPositions.y = getPositions().y;
    setPositions(Positions(getPositions().x, getPositions().y + (speed * dt)));
}

void Dynamic::moveLeft(float dt) {
    oldPositions.x = getPositions().x;
    setPositions(Positions(getPositions().x - (speed * dt), getPositions().y));
}

void Dynamic::moveRight(float dt) {
    oldPositions.x = getPositions().x;
    setPositions(Positions(getPositions().x + (speed * dt), getPositions().y));
}

MovingStatus Dynamic::getStatus() {
    return status;
}

void Dynamic::setStatus(MovingStatus status) {
    this->status = status;
}

MovingDirection Dynamic::getDirection() {

    return direction;
}

void Dynamic::setDirection(MovingDirection direction) {
    this->direction = direction;
}

void Dynamic::draw(std::shared_ptr<sf::RenderWindow> window) {
    switch (getStatus()) {
        case MOVING:
            switch (getDirection()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame * 32, 96, 32, 32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame * 32, 0, 32, 32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame * 32, 32, 32, 32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame * 32, 64, 32, 32));
                    break;
            };
            break;
        case IDLE:

            break;
        case STOP:
            //x=32 + value of dir(y)
            switch (getDirection()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
                    break;
            };
            break;
    };
    window->draw(sprite);
}

void Dynamic::update(const float dt) {

}

SpriteData Dynamic::getSpriteData() {
    return spriteData;
}

void Dynamic::setSpriteData(SpriteData spriteData) {
    this->spriteData = spriteData;
}

Positions Dynamic::getOldPositions()  {
    return oldPositions;
}

void Dynamic::setOldPositions( Positions oldPositions) {
    this->oldPositions = oldPositions;
}


