//
// Created by Streaming on 2018-01-19.
//

#ifndef SFML_GAME_GROUND_H
#define SFML_GAME_GROUND_H


#include "Static.h"


class Ground
        : public Static {
private:
    siteOfPicture pictureSite;
    bool animated;
public:
    Ground() = delete;

    /// Default Static constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    /// \param collisionAble - Enum about the possibility to collision
    /// \param cSiteOfPic - Enum information about sprite positions
    Ground(float cX, float cY, int cWidth, int cHeight, IsCollidet collisionAble, siteOfPicture cSiteOfPic);

    ~Ground();

    /// Target to draw this entity
    /// @param window - shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window);

    /// update method, everything is update by dt value
    /// \param dt - float value
    void update(const float dt);

};


#endif //SFML_GAME_GROUND_H
