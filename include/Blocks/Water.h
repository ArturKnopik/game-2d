//
// Created by Streaming on 2018-01-19.
//

#ifndef SFML_GAME_WATER_H
#define SFML_GAME_WATER_H


#include "Static.h"

class Water
        : public Static {
private:
  //  SpriteData dataSprite;
    siteOfPicture pictureSite;
    bool animated;
public:
    Water() = delete;

    /// Default Water constructor
    /// @param cX - global position x of Player
    /// @param cY - global position y of Player
    /// @param cWidth - Width sprite(affect collision to)
    /// @param cHeight - Height sprite(affect collision to)
    /// \param cAnimated - define animated status
    /// \param cSiteOfPic - set picture to draw
    Water(float cX, float cY, int cWidth, int cHeight, AnimatedEnum cAnimated, siteOfPicture cSiteOfPic);

    ~Water();

    /// Target to draw this entity,
    /// @param window - std::shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window);

    /// update method
    /// \param dt - float value
    void update(const float dt);
};


#endif //SFML_GAME_WATER_H
