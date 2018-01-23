//
// Created by Root on 13.01.2018.
//

#include <iostream>
#include "Blocks/Dynamic.h"

Dynamic::Dynamic(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        :Entity(cX, cY, cWidth, cHeight), speed(cSpeed)
{
    setCollisionStatus(CAN_BE_COLLIDET);
    texture.setSmooth(true);
    if(speed<0)
    {
        speed=speed*-1;
    }
    dir=DOWN;
    status=STOP;
    oldPositions=positions;
    sprite.setPosition(positions.x,positions.y);
}

void Dynamic::moveUp(float dt)
{
    oldPositions.y=positions.y;
    positions.y=positions.y-(speed*dt);
}

void Dynamic::moveDown(float dt)
{
    oldPositions.y=positions.y;
    positions.y=positions.y+(speed*dt);
}

void Dynamic::moveLeft(float dt)
{
    oldPositions.x=positions.x;
    positions.x=positions.x-(speed*dt);
}

void Dynamic::moveRight(float dt)
{
    oldPositions.x=positions.x;
    positions.x=positions.x+(speed*dt);
}

MovingStatus Dynamic::getStatus() const
{
    return status;
}

void Dynamic::setStatus(MovingStatus status)
{
    this->status = status;
}

MovingDirectory Dynamic::getDirectory() const
{
    return dir;
}

void Dynamic::setDir(MovingDirectory dir)
{
    this->dir=dir;
}

void Dynamic::draw(std::shared_ptr<sf::RenderWindow> window)
{
    switch (getStatus()) {
        case MOVING:
            switch (getDirectory()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame*32,96,32,32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame*32,0,32,32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame*32,32,32,32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(spriteData.currentFrame*32,64,32,32));
                    break;
            };
            break;
        case IDLE:

            break;
        case STOP:
            //x=32 + value of dir(y)
            switch (getDirectory()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(32,96,32,32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(32,0,32,32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(32,32,32,32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(32,64,32,32));
                    break;
            };
            break;
    };
    window->draw(sprite);
}

void Dynamic::update(const float dt)
{

}
