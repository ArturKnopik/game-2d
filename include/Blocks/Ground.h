//
// Created by Streaming on 2018-01-19.
//

#ifndef SFML_GAME_GROUND_H
#define SFML_GAME_GROUND_H



#include "Static.h"


class Ground
: public Static
{
private:
    siteOfPicture pictureSite;
    bool animated;
public:
    Ground()=delete;
    Ground(float cX,float cY, int cWidth, int cHeight, IsCollidet collisionAble, siteOfPicture cSiteOfPic);
    ~Ground();
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void update(const float dt);

};


#endif //SFML_GAME_GROUND_H
