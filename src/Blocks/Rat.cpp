//
// Created by Root on 18.01.2018.
//

#include "Blocks/Rat.h"

Rat::Rat(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        : Creature(cX, cY, cWidth, cHeight, cSpeed) {
    getRandomMovment();
    setCollisionAble(CAN_BE_COLLIDET);
    if (texture.loadFromFile("resource/image/EnemyGraphic.png")) {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
        sprite.setPosition(cX, cY);
    };

}

void Rat::draw(std::shared_ptr<sf::RenderWindow> window) {
    switch (getStatus()) {
        case MOVING:
            switch (getDirection()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 96, 32, 32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 0, 32, 32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 32, 32, 32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 64, 32, 32));
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

void Rat::update(const float dt) {
    currentTimeToChangeStateAndDir += dt;
    if (currentTimeToChangeStateAndDir > timeToChangeStateAndDir) {
        currentTimeToChangeStateAndDir = 0;
        getRandomMovment();
    }

    if (getCollsionStatus() == CAN_BE_COLLIDET) {
        setOldPositions(getPositions());
        sprite.setPosition(getPositions().x, getPositions().y);
    } else {
        setPositions(getOldPositions());
        getRandomMovment();
    }
    switch (getStatus()) {

        case MOVING: {
            SpriteData temp;

            temp = getSpriteData();
            temp.currentTime += dt;
            if (temp.currentTime >= temp.timeToNextFrame) {
                temp.currentTime = 0;
                if (temp.currentFrame >= temp.numbersOfFrame) {
                    temp.currentFrame = 0;
                } else {
                    temp.currentFrame++;
                }
            }
            setSpriteData(temp);


            switch (getDirection()) {
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
        }
        case IDLE:
            // std::cout<<"IDLE"<<std::endl;
            break;
        case STOP:

            break;
    };
    sprite.setPosition(getPositions().x, getPositions().y);
}

void Rat::getRandomMovment() {
    timeToChangeStateAndDir = ((rand() % 70) * 100000) + 5000000;
    int randomStatus = rand() % 2;
    switch (randomStatus) {
        case 0:
            setStatus(STOP);
            break;
        case 1:
            setStatus(MOVING);
            int randomDir = rand() % 4;
            switch (randomDir) {
                case 0:
                    setDirection(UP);
                    break;
                case 1:
                    setDirection(DOWN);
                    break;
                case 2:
                    setDirection(LEFT);
                    break;
                case 3:
                    setDirection(RIGHT);
                    break;
            }

            break;
    }
}
