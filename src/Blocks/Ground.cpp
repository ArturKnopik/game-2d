//
// Created by Streaming on 2018-01-19.
//

#include "Blocks/Ground.h"

Ground::Ground(float cX, float cY, int cWidth, int cHeight, bool collisionAble, siteOfPicture cSiteOfPic)
        : Static(cX, cY, cWidth, cHeight), pictureSite(cSiteOfPic)
{

    setCollsion(collisionAble);
    if(texture.loadFromFile("resource/image/Grass.png"))
    {
        sprite.setTexture(texture);
        switch (pictureSite)
        {
            case NW:
                sprite.setTextureRect(sf::IntRect(0,0,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case N:
                sprite.setTextureRect(sf::IntRect(32,0,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case NE:
                sprite.setTextureRect(sf::IntRect(64,0,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case W:
                sprite.setTextureRect(sf::IntRect(0,32,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case C:
                sprite.setTextureRect(sf::IntRect(32,32,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case E:
                sprite.setTextureRect(sf::IntRect(64,32,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case SW:
                sprite.setTextureRect(sf::IntRect(0,64,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case S:
                sprite.setTextureRect(sf::IntRect(32,64,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
            case SE:
                sprite.setTextureRect(sf::IntRect(64,64,spriteData.spriteWidth,spriteData.spriteHeight));
                break;
        }
    };
    sprite.setPosition(positions.x, positions.y);

}

Ground::~Ground()
{

}

void Ground::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(sprite);
}

void Ground::update(const float dt)
{

}
