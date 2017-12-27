//
// Created by Streaming on 2017-12-13.
//

#include "Game.h"
#include "GameState.h"
#include <iostream>
#include "settings.cpp"

Game::Game()
{
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Small Marrio Game");
    window.setFramerateLimit(FPS);
}



void Game::pushState(std::shared_ptr<GameState> state)
{
    states.push_back(state);
}

void Game::popState()
{
    //delete states[states.size() - 1];
    states.pop_back();
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
      //  std::cout << "Game::Nullprt |  ";
    }
    else
    {
        return states.back();
     //   std::cout << "Game::CurrentState  |  ";
    }
}


void Game::gameLoop()
{
    sf::Clock clock;
    std::cout << "Game::GameLoop  |  ";
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float  dt = elapsed.asSeconds();
        if (CurrentState() == nullptr)
        {
            continue;
        }
        CurrentState()->input();
        CurrentState()->update(dt);
        window.clear();
        CurrentState()->draw(dt);
        window.display();
    }
}
