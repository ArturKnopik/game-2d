//
// Created by Streaming on 2018-01-24.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "PlayerInterface.h"

PlayerInterface::PlayerInterface()
{
    rect[0].setFillColor(sf::Color(10,10,10,255));
    rect[0].setPosition(0,0);
    rect[0].setSize(sf::Vector2f(250,720));

    rect[1].setFillColor(sf::Color(10,10,10,255));
    rect[1].setPosition(1000,0);
    rect[1].setSize(sf::Vector2f(280,720));

    rect[2].setFillColor(sf::Color(10,10,10,255));
    rect[2].setPosition(250,0);
    rect[2].setSize(sf::Vector2f(1000,60));

    rect[3].setFillColor(sf::Color(10,10,10,255));
    rect[3].setPosition(250,660);
    rect[3].setSize(sf::Vector2f(1000,60));
}


void PlayerInterface::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for(int i=0;i<4;i++)
    {
       window->draw(rect[i]);
    }

}

void PlayerInterface::update(float dt)
{

}
