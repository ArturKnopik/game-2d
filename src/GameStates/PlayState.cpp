//
// Created by Streaming on 2017-12-13.
//

#include <Blocks/Water.h>
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"


PlayState::~PlayState()
{
}

void PlayState::draw()
{
    for(int i=0;i<mapEntity.size();i++)
    {
        mapEntity[i]->draw(game->window);
    }
}

void PlayState::update(const float dt)
{
    system("CLS");
    ch.checkEntityInhArray(mapEntity);

    cSpawner->spawnCreatureDeltaTime(dt);

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
                    //creatureVector.clear();
                break;
        }
    }
}

PlayState::PlayState(std::shared_ptr<Game> game)
{
    event=std::make_shared<sf::Event>();

    this->game = game;
    player = std::make_shared<Player>(200,200,32,32 ,0.0001);
    player->setCollisionAble(CAN_BE_COLLIDET);

    mapEntity.push_back(player);
    mapEntity.push_back(std::make_shared<Water>(68,132,32,32,CAN_NOT_BE_ANIMATED,C));
   /* mapEntity.push_back(std::make_shared<Water>(68,164,32,32,CAN_BE_ANIMATED,C));
    mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
    //
    mapEntity.push_back(std::make_shared<Water>(100,196,32,32,CAN_BE_ANIMATED,C));
    mapEntity.push_back(std::make_shared<Water>(100,228,32,32,CAN_BE_ANIMATED,C));
    mapEntity.push_back(std::make_shared<Water>(100,260,32,32,CAN_BE_ANIMATED,C));
    /*
    mapEntity.push_back(std::make_shared<Water>(100,92,32,32,CAN_BE_ANIMATED,C));
    mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
    mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
    mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));

    mapEntity.push_back(std::make_shared<Ground>(100,100,32,32,IS_COLLIDET,C));
    mapEntity.push_back(std::make_shared<Ground>(68,68,32,32,IS_COLLIDET,C));
    mapEntity.push_back(std::make_shared<Ground>(68,100,32,32,IS_COLLIDET,W));
    mapEntity.push_back(std::make_shared<Ground>(100,132,32,32,IS_COLLIDET,C));
    */
    mapEntity.push_back(std::make_shared<Ground>(68,132,32,32,IS_COLLIDET,SW));

    cSpawner=std::make_shared<CreatureSpawner> (150,250, mapEntity, RAT, 4000000);

}
