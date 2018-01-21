//
// Created by Streaming on 2017-12-13.
//

#include "Game.h"
#include "GameStates/GameState.h"
#include <iostream>
#include "settings.cpp"

Game::Game()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window=std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(WIDTH, HEIGHT), "Small Game", sf::Style::Titlebar, settings);
    window->setFramerateLimit(FPS);

}


/*!
 *
 * @param state
 */
void Game::pushState(std::shared_ptr<GameState> state)
{
    states.push_back(state);
}

void Game::popState() {
    if (!states.empty())
    {
        states.pop_back();
    }
}

Game::~Game()
{
    while (!states.empty())
        popState();
}

std::shared_ptr<GameState> Game::CurrentState()
{
    if (states.empty())
    {
        return nullptr;
    }
    else
    {
        return states.back();
    }
}


void Game::gameLoop()
{
    sf::Clock clock;
    while (window->isOpen())
    {
        sf::Time elapsed = clock.restart();
        float  dt = elapsed.asMicroseconds();
        CurrentState()->input();
        CurrentState()->update(dt);
        window->clear();
        CurrentState()->draw(dt);
        window->display();
    }
}
