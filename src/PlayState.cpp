//
// Created by Streaming on 2017-12-13.
//

#include "PlayState.h"
#include "MenuState.h"
#include "PauseState.h"

#include "BasicButton.h"

#include <SFML/Graphics.hpp>
#include "GameState.h"

PlayState::~PlayState()
{
}

void PlayState::draw(const float dt)
{
}

void PlayState::update(const float dt)
{

}

void PlayState::input()
{
    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
                this->game->window.close();
                break;

                //pause game
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    game->pushState(std::unique_ptr<GameState> (new PauseState(game)));
                break;

        }
    }
}

PlayState::PlayState(std::shared_ptr<Game> game)
{
    std::cout << "PlayState::PlayState  |  ";
    this->game = game;

}
