//
// Created by Streaming on 2018-01-24.
//

#ifndef SFML_GAME_PLAYERINTERFACE_H
#define SFML_GAME_PLAYERINTERFACE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class PlayerInterface
{
private:
    sf::RectangleShape rect[4];
public:
    PlayerInterface();
    void init();
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void update(float dt);
};


#endif //SFML_GAME_PLAYERINTERFACE_H
