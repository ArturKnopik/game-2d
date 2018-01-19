//
// Created by Root on 18.01.2018.
//

#include "SimpleEnemy.h"

SimpleEnemy::SimpleEnemy(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        : Dynamic(cX, cY, cWidth, cHeight, cSpeed)
{
    if(texture.loadFromFile("resource/image/EnemyGraphic.png"))
    {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0,0,spriteData.spriteWidth,spriteData.spriteHeight));
        sprite.setPosition(cX,cY);
    };

}

void SimpleEnemy::draw(std::shared_ptr<sf::RenderWindow> window)
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

void SimpleEnemy::update(const float dt)
{

    switch (getStatus()) {
        case MOVING:
            spriteData.currentTime+=dt;
            if(spriteData.currentTime>=spriteData.timeToNextFrame)
            {
                spriteData.currentTime=0;
                if(spriteData.currentFrame>=spriteData.numbersOfFrame)
                {
                    spriteData.currentFrame=0;
                }
                else
                {
                    spriteData.currentFrame++;
                }
            }

            switch (getDirectory()) {
                case UP:
                    setStatus(MOVING);
                    moveUp(dt);
                    break;
                case DOWN:
                    setStatus(MOVING);
                    moveDown(dt);
                    break;
                case LEFT:
                    setStatus(MOVING);
                    moveLeft(dt);
                    break;
                case RIGHT:
                    setStatus(MOVING);
                    moveRight(dt);
                    break;
            };
            break;
        case IDLE:
            // std::cout<<"IDLE"<<std::endl;
            break;
        case STOP:

            break;
    };
    positions=oldPositions;
    sprite.setPosition(positions.x,positions.y);
}
