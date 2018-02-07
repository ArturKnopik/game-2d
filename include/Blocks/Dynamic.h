//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_DYNAMIC_H
#define SFML_GAME_DYNAMIC_H

#include "Blocks/Entity.h"

/// Enum stored dirrection information
enum MovingDirection {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

/// Enum stored status of movment
enum MovingStatus {
    IDLE = 0,
    MOVING = 1,
    STOP = 2
};
///
class Dynamic
        : public Entity {
private:
    MovingStatus status;
    MovingDirection direction;
    SpriteData spriteData;
    float speed;
    Positions oldPositions;
protected:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Dynamic() = delete;

/// Default Dynamic constructor
/// @param cX - global position  x of Player
/// @param cY - global position  y of Player
/// @param cWidth - Width player sprite(affect collision to)
/// @param cHeight - Height player sprite(affect collision to)
/// @param cSpeed - speed of Dynamic entity
    Dynamic(float cX, float cY, int cWidth, int cHeight, float cSpeed);

/// Allow moving Entity UP by speed value calculate with dt
/// \param dt -moving Up by dt value
    void moveUp(float dt);

/// Allow moving Entity DOWN by speed value calculate with dt
/// \param dt -moving Down by dt value
    void moveDown(float dt);

/// Allow moving Entity LEFT by speed value calculate with dt
/// \param dt -moving Left by dt value
    void moveLeft(float dt);

///Allow moving Entity RIGHT by speed value calculate with dtAllow moving Entity RIGHT by speed value calculate with dt
/// \param dt -moving Rigt by dt value
    void moveRight(float dt);

/// Target to draw this entity, can be override to create custom draw(...) method
/// \param window - Target to draw on it shared_ptr
    virtual void draw(std::shared_ptr<sf::RenderWindow> window);

/// update method, can be over override to create custom uptade(...) method
/// \param dt dt - single frame time, calculate
    virtual void update(const float dt);

/// Return curent status of movment
/// \return - MovingStatus Enum
    MovingStatus getStatus();

///  Allow to set new Status of movement
/// \param status - MovingStatus Enum
    void setStatus(MovingStatus status);

/// Return current direction
/// \return MovingDirection Enum
    MovingDirection getDirection();

/// Allow to set new direction
/// \param direction - MovingDirection Enum
    void setDirection(MovingDirection direction);

/// Return Srite informations
/// \return SpriteData obiect
    SpriteData getSpriteData();

/// Allow to set new Sprite informations
/// \param spriteData - SpriteData obiect
    void setSpriteData(SpriteData spriteData);

/// return previous value of positions
/// \return Positions obiect
    Positions getOldPositions();

/// Set previous value of positions
/// \param oldPositions - obiect
    void setOldPositions(Positions oldPositions);
};


#endif //SFML_GAME_DYNAMIC_H
