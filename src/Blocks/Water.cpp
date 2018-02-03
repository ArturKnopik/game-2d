//
// Created by Streaming on 2018-01-19.
//

#include "Blocks/Water.h"

Water::Water(float cX, float cY, int cWidth, int cHeight, AnimatedEnum cAnimated, siteOfPicture cSiteOfPic)
        : Static(cX, cY, cWidth, cHeight), pictureSite(cSiteOfPic), animated(cAnimated) {
    SpriteData tempSpriteData;
    tempSpriteData.currentFrame = 0;
    tempSpriteData.currentTime = 0;
    tempSpriteData.timeToNextFrame = 900000;
    setCollisionAble(CAN_BE_COLLIDET);
    if (texture.loadFromFile("resource/image/Water.png")) {
        sprite.setTexture(texture);
        if (animated == CAN_NOT_BE_ANIMATED) {
            switch (pictureSite) {
                case NW:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 0, getSpriteData().spriteOffsetY + 0,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case N:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 32, getSpriteData().spriteOffsetY + 0,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case NE:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 64, getSpriteData().spriteOffsetY + 0,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case W:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 0, getSpriteData().spriteOffsetY + 32,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case C:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 32, getSpriteData().spriteOffsetY + 32,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case E:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 64, getSpriteData().spriteOffsetY + 32,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case SW:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 0, getSpriteData().spriteOffsetY + 64,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case S:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 32, getSpriteData().spriteOffsetY + 64,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
                case SE:
                    sprite.setTextureRect(
                            sf::IntRect(getSpriteData().spriteOffsetX + 64, getSpriteData().spriteOffsetY + 64,
                                        getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                    break;
            }
        } else {

            tempSpriteData.spriteOffsetY = 96;
        }
    };
    setSpriteData(tempSpriteData);
    sprite.setPosition(getPositions().x, getPositions().y);

}

Water::~Water() {

}

void Water::draw(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(sprite);
}

void Water::update(const float dt) {
    if (animated == CAN_BE_ANIMATED) {

        SpriteData temp = getSpriteData();
        temp.currentTime += dt;
        if (temp.currentTime >= temp.timeToNextFrame) {
            temp.currentTime = 0;
            if (temp.currentFrame >= temp.numbersOfFrame) {
                temp.currentFrame = 0;
                temp.spriteOffsetX = 0;
            } else {
                temp.currentFrame++;
                temp.spriteOffsetX += 96;
            }
        }
        setSpriteData(temp);



        // Need Add sprite offset value to x and Y!
        switch (pictureSite) {
            case NW:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 0, getSpriteData().spriteOffsetY + 0,
                                    getSpriteData().spriteWidth,
                                    getSpriteData().spriteHeight));
                break;
            case N:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 32, getSpriteData().spriteOffsetY + 0,
                                    getSpriteData().spriteWidth,
                                    getSpriteData().spriteHeight));
                break;
            case NE:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 64, getSpriteData().spriteOffsetY + 0,
                                    getSpriteData().spriteWidth,
                                    getSpriteData().spriteHeight));
                break;
            case W:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 0, getSpriteData().spriteOffsetY + 32,
                                    getSpriteData().spriteWidth,
                                    getSpriteData().spriteHeight));
                break;
            case C:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 32, getSpriteData().spriteOffsetY + 32,
                                    getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case E:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 64, getSpriteData().spriteOffsetY + 32,
                                    getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case SW:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 0, getSpriteData().spriteOffsetY + 64,
                                    getSpriteData().spriteWidth,
                                    getSpriteData().spriteHeight));
                break;
            case S:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 32, getSpriteData().spriteOffsetY + 64,
                                    getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case SE:
                sprite.setTextureRect(
                        sf::IntRect(getSpriteData().spriteOffsetX + 64, getSpriteData().spriteOffsetY + 64,
                                    getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
        }
    }
}