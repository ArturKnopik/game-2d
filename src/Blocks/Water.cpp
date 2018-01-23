//
// Created by Streaming on 2018-01-19.
//

#include "Blocks/Water.h"

Water::Water(float cX, float cY, int cWidth, int cHeight, AnimatedEnum cAnimated, siteOfPicture cSiteOfPic)
        : Static(cX, cY, cWidth, cHeight), pictureSite(cSiteOfPic), animated(cAnimated)
{
    dataSprite.currentFrame=0;
    dataSprite.currentTime=0;
    spriteData.timeToNextFrame=900000;
    setCollisionAble(CollisionEnum::CAN_BE_COLLIDET);
    if(texture.loadFromFile("resource/image/Water.png"))
    {
        sprite.setTexture(texture);
       if(animated==CAN_NOT_BE_ANIMATED)
        {
            switch (pictureSite) {
                case NW:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX + 0,spriteData.spriteOffsetY+0,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case N:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+32,spriteData.spriteOffsetY+0,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case NE:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+64,spriteData.spriteOffsetY+0,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case W:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+0,spriteData.spriteOffsetY+32,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case C:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+32,spriteData.spriteOffsetY+32,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case E:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+64,spriteData.spriteOffsetY+32,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case SW:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+0,spriteData.spriteOffsetY+64,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case S:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+32,spriteData.spriteOffsetY+64,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
                case SE:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+64,spriteData.spriteOffsetY+64,spriteData.spriteWidth,spriteData.spriteHeight));
                    break;
            }
        }
        else
       {
           spriteData.spriteOffsetY=96;
       }
    };
    sprite.setPosition(positions.x, positions.y);

}

Water::~Water()
{

}

void Water::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(sprite);
}

void Water::update(const float dt)
{
    if(animated==CAN_BE_ANIMATED)
    {
        spriteData.currentTime += dt;
        if (spriteData.currentTime >= spriteData.timeToNextFrame)
        {
            spriteData.currentTime = 0;
            if (spriteData.currentFrame >= spriteData.numbersOfFrame)
            {
                spriteData.currentFrame = 0;
                spriteData.spriteOffsetX=0;
            } else {
                spriteData.currentFrame++;
                spriteData.spriteOffsetX+=96;
            }
        }
        // Need Add sprite offset value to x and Y!
        switch (pictureSite) {
            case NW:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX + 0,spriteData.spriteOffsetY+0,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case N:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+32,spriteData.spriteOffsetY+0,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case NE:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+64,spriteData.spriteOffsetY+0,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case W:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+0,spriteData.spriteOffsetY+32,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case C:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+32,spriteData.spriteOffsetY+32,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case E:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+64,spriteData.spriteOffsetY+32,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case SW:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+0,spriteData.spriteOffsetY+64,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case S:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+32,spriteData.spriteOffsetY+64,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case SE:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteOffsetX+64,spriteData.spriteOffsetY+64,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
        }
    }
   if(getCollsionStatus()==IS_COLLIDET)
    {
        std::cout<<"WATER colidet = true"<<std::endl;
    }
    else
    {
        std::cout << "WATER colidet = false" << std::endl;
    }
}