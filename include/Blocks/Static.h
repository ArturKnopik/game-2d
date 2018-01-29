//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_STATIC_H
#define SFML_GAME_STATIC_H

#include "Blocks/Entity.h"

/// Enum stored sprite position by compass (C=center)
enum siteOfPicture {
    NW = 0,  N = 1,  NE = 2,
    W  = 3,  C = 4,  E  = 5,
    SW = 6,  S = 7,  SE = 8
};
/// Enum stored information about about the possibility to animation obiect
enum AnimatedEnum {
    CAN_BE_ANIMATED = 0,
    CAN_NOT_BE_ANIMATED = 1
};

class Static :
        public Entity {
private:
    SpriteData spriteData;
protected:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Static() = delete;
    /// Default Static constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    Static(float cX, float cY, int cWidth, int cHeight);
    /// Return Srite informations
    /// \return SpriteData obiect
    SpriteData getSpriteData();
    void setSpriteData(SpriteData spriteData);
};


#endif //SFML_GAME_STATIC_H
