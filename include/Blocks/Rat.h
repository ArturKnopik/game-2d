//
// Created by Root on 18.01.2018.
//

#ifndef SFML_GAME_SIMPLEENEMY_H
#define SFML_GAME_SIMPLEENEMY_H


#include "Creature.h"

class Rat
        : public Creature {
private:
    int timeToChangeStateAndDir = 5000000;
    int currentTimeToChangeStateAndDir = 0;

    // float idleTime; //1000000 = 1s
    /// create new random movnent for Rat
    void getRandomMovment();

public:
    Rat() = delete;

    /// Default Rat constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    /// @param cSpeed - Speed of Rat
    Rat(float cX, float cY, int cWidth, int cHeight, float cSpeed);

    /// Target to draw this entity,
    /// @param window - std::shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window);

    /// update method
    /// \param dt - float value
    void update(const float dt) override;

};


#endif //SFML_GAME_SIMPLEENEMY_H
