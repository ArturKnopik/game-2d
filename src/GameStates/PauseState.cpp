//
// Created by Streaming on 2017-12-13.
//

#include "GameStates/PauseState.h"
#include <iostream>




PauseState::PauseState(std::shared_ptr<Game> game)
{
    this->game = game;
    game->window->setView(game->window->getDefaultView());
}

PauseState::~PauseState()
{

}

void PauseState::draw()
{
    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f(100, 100));
    rect.setSize(sf::Vector2f(100, 100));
    rect.setFillColor(sf::Color::Blue);
    game->window->draw(rect);

}

void PauseState::update(const float dt)
{
    game->window->setView(game->window->getDefaultView());
}

void PauseState::input()
{


    while (game->window->pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
                game->window->close();
                break;

                /* Change Between game states */
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    game->popState();
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    game->popState();
                    game->popState();
                }

        }
    }
}

