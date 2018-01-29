//
// Created by Streaming on 2018-01-29.
//

#include "SimpeHouse1.h"

SimpeHouse1::SimpeHouse1(float cX, float cY, int cWidth, int cHeight)
        : Static(cX, cY, cWidth, cHeight) {
    setCollisionAble(CAN_BE_COLLIDET);
    if (texture.loadFromFile("resource/image/House1.png")) {
        sprite.setTexture(texture);
    }
    sprite.setPosition(getPositions().x, getPositions().y);
    SpriteData tempSpriteData=getSpriteData();
    tempSpriteData.spriteWidth=96;
    tempSpriteData.spriteHeight=96;
    setSpriteData(tempSpriteData);
    setSize(96,96);

}

void SimpeHouse1::draw(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(sprite);
}

void SimpeHouse1::update(const float dt) {

}
