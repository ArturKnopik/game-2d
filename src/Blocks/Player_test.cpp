//
// Created by Streaming on 2018-02-04.
//

#include "Blocks/Player_test.h"

Player_test::Player_test(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        : Dynamic(cX, cY, cWidth, cHeight, cSpeed) {
    setTypeOfEntity(PLAYER);
    setCollisionAble(CollisionEnum::CAN_BE_COLLIDET);
    if (texture.loadFromFile("resource/image/playerJMP.png")) {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
        sprite.setPosition(cX, cY);
    };

}

void Player_test::draw(std::shared_ptr<sf::RenderWindow> window) {

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


void Player_test::update(const float dt) {

    if (getCollsionStatus() == IsCollidet::NO_COLLISION) {
        setPositions(getOldPositions());
    } else {
        setOldPositions(getPositions());

        sprite.setPosition(getPositions().x * 32, getPositions().y * 32);
    }


    switch (getStatus()) {
        case MOVING: {
            if(isMoving()) {
                SpriteData tempSpriteData;
                tempSpriteData = getSpriteData();
                tempSpriteData.currentTime += dt;
                if (tempSpriteData.currentTime >= tempSpriteData.timeToNextFrame) {
                    tempSpriteData.currentTime = 0;
                    if (tempSpriteData.currentFrame >= tempSpriteData.numbersOfFrame) {
                        tempSpriteData.currentFrame = 0;
                    } else {
                        tempSpriteData.currentFrame++;
                    }
                }
                setSpriteData(tempSpriteData);
            }

        }

            switch (getDirection()) {
                case UP:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveUp(dt);
                    moving = true;
                    setStatus(STOP);
                    break;
                case DOWN:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveDown(dt);
                    moving = true;
                    setStatus(STOP);
                    break;
                case LEFT:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveLeft(dt);
                    moving = true;
                    setStatus(STOP);
                    break;
                case RIGHT:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveRight(dt);
                    moving = true;
                    setStatus(STOP);
                    break;

            };


            break;
        case IDLE:
            std::cout << "PLAYER: IDLE STATUS " << std::endl;

            break;
        case STOP:

            break;
    };


    if (getStatus() != IDLE) {
        idleTime += dt;
    }

    if (timeToMove <= currentTimeToMove) {
        currentTimeToMove = 0;
        moving = false;
        std::cout << "dont moving" << currentTimeToMove << std::endl;
    } else {
        moving = true;
        currentTimeToMove +=dt;
        std::cout << "still moving: " << currentTimeToMove << std::endl;
    }

}

void Player_test::input(std::shared_ptr<sf::Event> event) {
    // need change to switch()
    if (!isMoving()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            setStatus(MOVING);
            setDirection(UP);
            moving = true;
            return;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            setStatus(MOVING);
            setDirection(DOWN);
            moving = true;
            return;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            setStatus(MOVING);
            setDirection(LEFT);
            moving = true;
            return;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            setStatus(MOVING);
            setDirection(RIGHT);
            moving = true;
            return;
        } else {
            moving = false;
            if (idleTime > 8000000) {
                setStatus(IDLE);
            } else {
                setStatus(STOP);
            }
        }
    }
}

void Player_test::moveUp(float dt) {
    setOldPositions(Positions(getPositions().x, getPositions().y));
    setPositions(Positions(getPositions().x, getPositions().y - 1));
}

void Player_test::moveDown(float dt) {
    setOldPositions(Positions(getPositions().x, getPositions().y));
    setPositions(Positions(getPositions().x, getPositions().y + 1));
}

void Player_test::moveLeft(float dt) {
    setOldPositions(Positions(getPositions().x, getPositions().y));
    setPositions(Positions(getPositions().x - 1, getPositions().y));
}

void Player_test::moveRight(float dt) {
    setOldPositions(Positions(getPositions().x, getPositions().y));
    setPositions(Positions(getPositions().x + 1, getPositions().y));
}

bool Player_test::isMoving() {
    return moving;
}
