//
// Created by Streaming on 2018-02-04.
//

#ifndef SFML_GAME_PLAYER_TEST_H
#define SFML_GAME_PLAYER_TEST_H


#include "Dynamic.h"
struct offSet
{
    float x=0;
    float y=0;
};

class Player_test : public Dynamic {
private:
    int idleTime = 0; //1000000 = 1s
    offSet offsetSprite;
    int timeToMove=500000;
    int currentTimeToMove=0;
    bool moving=false;
    MovingDirection directionAnimate=DOWN;
    bool isMoving();
    bool movingSprite=false;
public:
    /// Default Player constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    /// @param cSpeed - Speed of player
    Player_test(float cX, float cY, int cWidth, int cHeight, float cSpeed);

    /// Target to draw this entity,
    /// @param window - std::shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window) ;

    /// update method
    /// \param dt - float value
    void update(const float dt) ;

    /// Allow entity to react when used keyboard and mouse
    /// \param event  - std::shared_ptr<sf::Event> obiect
    void input(std::shared_ptr<sf::Event> event);

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

};


#endif //SFML_GAME_PLAYER_TEST_H
