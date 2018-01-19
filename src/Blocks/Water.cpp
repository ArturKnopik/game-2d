//
// Created by Streaming on 2018-01-19.
//

#include "Blocks/Water.h"

Water::Water(float cX, float cY, int cWidth, int cHeight, bool cAnimated, siteOfPicture cSiteOfPic)
        : Static(cX, cY, cWidth, cHeight), pictureSite(cSiteOfPic), animated(cAnimated)
{
    dataSprite.currentFrame=0;
    dataSprite.currentTime=0;
    setCollsion(true);
    if(texture.loadFromFile("resource/image/Water.png"))
    {
        sprite.setTexture(texture);
       if(!animated)
        {
            switch (pictureSite) {
                case NW:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth, spriteData.spriteHeight, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case N:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+32, spriteData.spriteHeight, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case NE:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+64, spriteData.spriteHeight, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case W:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth, spriteData.spriteHeight+32, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case C:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+32, spriteData.spriteHeight+32, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case E:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+64, spriteData.spriteHeight+32, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case SW:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth, spriteData.spriteHeight+64, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case S:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+32, spriteData.spriteHeight+ 64, spriteData.spriteWidth, spriteData.spriteHeight));
                    break;
                case SE:
                    sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+64, spriteData.spriteHeight+64, spriteData.spriteWidth, spriteData.spriteHeight));
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

Water::~Water() {

}

void Water::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(sprite);
}

void Water::update(const float dt)
{
    if(animated)
    {
        spriteData.currentTime += dt;
        if (spriteData.currentTime >= spriteData.timeToNextFrame)
        {
            spriteData.currentTime = 0;
            if (spriteData.currentFrame >= spriteData.numbersOfFrame)
            {
                spriteData.currentFrame = 0;
                spriteData.spriteOffsetY=0;
            } else {
                spriteData.currentFrame++;
                spriteData.spriteOffsetY+=96;
            }
        }
        // Need Add sprite offset value to x and Y!
        switch (pictureSite) {
            case NW:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+s, spriteData.spriteHeight, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case N:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+32, spriteData.spriteHeight, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case NE:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+64, spriteData.spriteHeight, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case W:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth, spriteData.spriteHeight+32, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case C:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+32, spriteData.spriteHeight+32, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case E:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+64, spriteData.spriteHeight+32, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case SW:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth, spriteData.spriteHeight+64, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case S:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+32, spriteData.spriteHeight+ 64, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
            case SE:
                sprite.setTextureRect(sf::IntRect(spriteData.spriteWidth+64, spriteData.spriteHeight+64, spriteData.spriteWidth, spriteData.spriteHeight));
                break;
        }
    }

}