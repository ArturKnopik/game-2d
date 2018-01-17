//
// Created by Streaming on 2017-12-13.
//

#include "GameStates/PlayState.h"
#include "GameStates/MenuState.h"
#include "GameStates/PauseState.h"

#include "Buttoms/BasicButton.h"

#include <SFML/Graphics.hpp>
#include "GameStates/GameState.h"
PlayState::~PlayState()
{
}

void PlayState::draw(const float dt)
{
    for(int i=0;i<creatureVector.size();i++)
    {
        creatureVector[i]->draw(game->window);
    }
    testBlock1->draw(game->window);
    testBlock2->draw(game->window);
    player->draw(game->window);
}

void PlayState::update(const float dt)
{
    cChecker1.spawnCreature(sf::seconds(5));
    cChecker.spawnCreatureDeltaTime(4000000,dt);
    ch.checkAABB(testBlock1, testBlock2);
    for(int i=0;i<creatureVector.size();i++)
    {
        creatureVector[i]->update(dt);
    }
    testBlock1->update(dt);
    testBlock2->update(dt);
    player->update(dt);
   // cChecker.drawTime(sf::seconds(1.5));

}

void PlayState::input()
{
    player->input(event);
    while (this->game->window->pollEvent(*event.get()))
    {
        switch (event->type)
        {
            case sf::Event::Closed:
                this->game->window->close();
                break;

            case sf::Event::KeyPressed:
                if (event->key.code == sf::Keyboard::Escape)
                    game->pushState(std::make_shared<PauseState>(game));

                if (event->key.code == sf::Keyboard::F1)
                    creatureVector.clear();
                break;


        }
    }
}

PlayState::PlayState(std::shared_ptr<Game> game)
{
    event=std::make_shared<sf::Event>();
   cChecker.init(creatureVector);
    cChecker1.init(creatureVector);
    this->game = game;
    player = std::make_shared<Player>(300,300,32,32 ,0.0001);
    testBlock1 = std::make_shared<Block>(100, 100, 60, 60, sf::Color::Blue);
    testBlock2 = std::make_shared<Block>(150, 150, 90, 90, sf::Color::Green);

}
