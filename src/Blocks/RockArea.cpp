//
// Created by Streaming on 2018-01-29.
//

#include "Blocks/RockArea.h"

RockArea::RockArea(float cX, float cY, int cWidth, int cHeight, siteOfPicture cSiteOfPic)
        : Static(cX, cY, cWidth, cHeight), pictureSite(cSiteOfPic) {
    setCollisionAble(CAN_NOT_BE_COLLIDET);
    if (texture.loadFromFile("resource/image/Rock.png")) {
        sprite.setTexture(texture);
        switch (pictureSite) {
            case NW:
                sprite.setTextureRect(sf::IntRect(0, 0, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case N:
                sprite.setTextureRect(sf::IntRect(32, 0, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case NE:
                sprite.setTextureRect(sf::IntRect(64, 0, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case W:
                sprite.setTextureRect(sf::IntRect(0, 32, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case C:
                sprite.setTextureRect(sf::IntRect(32, 32, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case E:
                sprite.setTextureRect(sf::IntRect(64, 32, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case SW:
                sprite.setTextureRect(sf::IntRect(0, 64, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case S:
                sprite.setTextureRect(sf::IntRect(32, 64, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
            case SE:
                sprite.setTextureRect(sf::IntRect(64, 64, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
                break;
        }
    };
    sprite.setPosition(getPositions().x, getPositions().y);

}

void RockArea::draw(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(sprite);
}

void RockArea::update(const float dt) {

}
