//
// Created by Streaming on 2018-01-29.
//

#ifndef SFML_GAME_SIMPEHOUSE1_H
#define SFML_GAME_SIMPEHOUSE1_H


#include "Static.h"

class SimpeHouse1 : public Static{
public:
    SimpeHouse1()=delete;
    /// Default SimpeHouse1 constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    SimpeHouse1(float cX, float cY, int cWidth, int cHeight);

    /// Target to draw this entity
    /// @param window - shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window);

    /// update method, everything is update by dt value
    /// \param dt - float value
    void update(const float dt);

};


#endif //SFML_GAME_SIMPEHOUSE1_H
