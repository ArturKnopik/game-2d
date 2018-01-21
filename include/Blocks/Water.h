//
// Created by Streaming on 2018-01-19.
//

#ifndef SFML_GAME_WATER_H
#define SFML_GAME_WATER_H


#include "Static.h"

class Water
: public Static
{
private:
    SpriteData dataSprite;
    siteOfPicture pictureSite;
    bool animated;
public:
    Water()=delete;
    Water(float cX, float cY, int cWidth, int cHeight, AnimatedEnum cAnimated, siteOfPicture cSiteOfPic);
    ~Water();
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void update(const float dt);
};


#endif //SFML_GAME_WATER_H
