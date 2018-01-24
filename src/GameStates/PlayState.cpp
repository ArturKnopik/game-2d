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
     // gameArea
    gameAreaViewe.setCenter(player->oldPositions.x+player->getSpriteData().spriteWidth/2,
                            player->oldPositions.y+player->getSpriteData().spriteHeight/2);
    game->window->setView(gameAreaViewe);
    //for(auto i=mapEntity.size(); i!=0;i--)
    std::vector<std::shared_ptr<Entity>>::reverse_iterator iter;
    for(iter=mapEntity.rbegin();iter != mapEntity.rend();iter++)
    {
        if((*iter)->positions.x - player->positions.x<400 && (*iter)->positions.x - player->positions.x>-400 &&
           (*iter)->positions.y - player->positions.y<300 && (*iter)->positions.y - player->positions.y>-300)
        {
            (*iter)->draw(game->window);
        }
    }

    game->window->setView(game->window->getDefaultView());
    //interface

    pInterface.draw(game->window);
    
}

void PlayState::update(const float dt)
{
    system("CLS");
    ch.checkEntityInhArray(mapEntity);

    cSpawner->spawnCreatureDeltaTime(dt);
    std::vector<std::shared_ptr<Entity>>::iterator iter;
    for(iter=mapEntity.begin();iter != mapEntity.end();iter++)
    {
        (*iter)->update(dt);
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
                    gameAreaViewe.zoom(1.3);

                if (event->key.code == sf::Keyboard::F2)
                    gameAreaViewe.zoom(0.7);
                break;
        }
    }
}

PlayState::PlayState(std::shared_ptr<Game> game)
    {
        event=std::make_shared<sf::Event>();

        player = std::make_shared<Player>(200,200,32,32 ,0.0001);

        gameAreaViewe.reset(sf::FloatRect(200, 60, 800, 600));
        gameAreaViewe.setCenter(player->oldPositions.x+player->getSpriteData().spriteWidth,player->oldPositions.y+player->getSpriteData().spriteHeight);
        gameAreaViewe.setViewport(sf::FloatRect(0.19f, 0.08f, 0.62f, 0.84f));
        gameAreaViewe.zoom(0.7f);
        this->game = game;

        mapEntity.push_back(player);
        mapEntity.push_back(std::make_shared<Water>(68,132,32,32,CAN_NOT_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(68,164,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,196,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,228,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,260,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,92,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Water>(100,164,32,32,CAN_BE_ANIMATED,C));
        mapEntity.push_back(std::make_shared<Ground>(100,100,32,32,IS_COLLIDET,C));
        mapEntity.push_back(std::make_shared<Ground>(68,68,32,32,IS_COLLIDET,C));
        mapEntity.push_back(std::make_shared<Ground>(68,100,32,32,IS_COLLIDET,W));
        mapEntity.push_back(std::make_shared<Ground>(100,132,32,32,IS_COLLIDET,C));
        mapEntity.push_back(std::make_shared<Ground>(68,132,32,32,IS_COLLIDET,SW));

        cSpawner=std::make_shared<CreatureSpawner> (150,250, mapEntity, RAT, 4000000);

}
