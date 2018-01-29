//
// Created by Streaming on 2018-01-29.
//

#ifndef SFML_GAME_ROCK_H
#define SFML_GAME_ROCK_H


#include "Static.h"

class RockArea : public Static {
private:
    siteOfPicture pictureSite;
public:
    RockArea() = delete;

    /// Default Rock constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    /// \param cSiteOfPic - Enum information about sprite positions
    RockArea(float cX, float cY, int cWidth, int cHeight, siteOfPicture cSiteOfPic);

    /// Target to draw this entity
    /// @param window - shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window);

    /// update method, everything is update by dt value
    /// \param dt - float value
    void update(const float dt);

};


#endif //SFML_GAME_ROCK_H
