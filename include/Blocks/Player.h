//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_PLAYER_H
#define SFML_GAME_PLAYER_H

#include "Blocks/Dynamic.h"


class Player
        : public Dynamic {
private:
    int idleTime = 0; //1000000 = 1s
public:
    Player() = delete;

    /// Default Player constructor
    /// @param cX - global position  x of Player
    /// @param cY - global position  y of Player
    /// @param cWidth - Width player sprite(affect collision to)
    /// @param cHeight - Height player sprite(affect collision to)
    /// @param cSpeed - Speed of player
    Player(float cX, float cY, int cWidth, int cHeight, float cSpeed);

    /// Target to draw this entity,
    /// @param window - std::shared_ptr<sf::RenderWindow> obiect
    void draw(std::shared_ptr<sf::RenderWindow> window) override;

    /// update method
    /// \param dt - float value
    void update(const float dt);

    /// Allow entity to react when used keyboard and mouse
    /// \param event  - std::shared_ptr<sf::Event> obiect
    void input(std::shared_ptr<sf::Event> event);


};


#endif //SFML_GAME_PLAYER_H
