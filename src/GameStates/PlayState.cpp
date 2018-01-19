//
// Created by Streaming on 2017-12-13.
//

#include <Blocks/Water.h>
#include "GameStates/PlayState.h"
//#include "GameStates/MenuState.h"
#include "GameStates/PauseState.h"
//#include <SFML/Graphics.hpp>
//#include "GameStates/GameState.h"
//#include <cstdlib>

PlayState::~PlayState()
{
}

void PlayState::draw(const float dt)
{
    for(int i=0;i<mapEntity.size();i++)
    {
        mapEntity[i]->draw(game->window);
    }

    for(int i=0;i<creatureVector.size();i++)
    {
        creatureVector[i]->draw(game->window);
    }
    player->draw(game->window);
    simpleEnemy->draw(game->window);
}

void PlayState::update(const float dt)
{
    system("cls");
    cChecker1.spawnCreature(sf::seconds(5));
    cChecker.spawnCreatureDeltaTime(4000000,dt);
    // collsion player
    if(ch.checkAABB(player, simpleEnemy))
    {
        std::cout<<"Collsions: "<<std::endl;
       player->setCollsion(true);
        simpleEnemy->setCollsion(true);
    }
    else
    {
        player->setCollsion(false);
        simpleEnemy->setCollsion(false);
        std::cout<<std::endl;
    }

    for(int i=0;i<creatureVector.size();i++)
    {
        creatureVector[i]->update(dt);
    }

    player->update(dt);
    simpleEnemy->update(dt);
   // cChecker.drawTime(sf::seconds(1.5));

    for(int i=0;i<mapEntity.size();i++)
    {
        mapEntity[i]->update(dt);
    }

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
    player->positions.x=100;
    simpleEnemy = std::make_shared<Rat>(200,200,32,32 ,0.00002);
    mapEntity.push_back(std::make_shared<Water>(68,132,32,32,false,C));
    mapEntity.push_back(std::make_shared<Water>(68,164,32,32,true,C));
    mapEntity.push_back(std::make_shared<Water>(100,164,32,32,true,C));
    mapEntity.push_back(std::make_shared<Ground>(100,100,32,32,false,C));
    mapEntity.push_back(std::make_shared<Ground>(68,100,32,32,false,W));
    mapEntity.push_back(std::make_shared<Ground>(100,132,32,32,false,S));
    mapEntity.push_back(std::make_shared<Ground>(68,132,32,32,false,SW));



}
