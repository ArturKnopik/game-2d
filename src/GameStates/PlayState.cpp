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

    std::vector<std::shared_ptr<Entity>>::reverse_iterator iter;
    std::cout<<currentOffSet.x<< " : "<<currentOffSet.y<<std::endl;
    for(iter=mapEntity.rbegin();iter != mapEntity.rend();iter++)
    {
        if((*iter)->positions.x - player->positions.x<400 && (*iter)->positions.x - player->positions.x>-400 &&
           (*iter)->positions.y - player->positions.y<300 && (*iter)->positions.y - player->positions.y>-300)
        {

            (*iter)->draw(game->window);
        }
    }

    ch.mouseCheckerWitchEntity(mapEntity, game->window);
    ch.drawGrid(mapEntity,game->window);
}

void PlayState::update(const float dt)
{
    system("CLS");

    ch.getMapCollisionGridOnVisibleArea(mapEntity);
    viewe.setCenter(player->oldPositions.x, player->oldPositions.y);
    game->window->setView(viewe);
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

                if (event->key.code == sf::Keyboard::F1) {
                    viewe.zoom(0.7);
                }

                if (event->key.code == sf::Keyboard::F2) {
                    viewe.zoom(1.3);
                }
                break;

        }
    }
}

PlayState::PlayState(std::shared_ptr<Game> game)
    {
        event=std::make_shared<sf::Event>();

        player = std::make_shared<Player>(0,0,32,32 ,0.0001);


        this->game = game;
        viewe.setSize(game->window->getSize().x, game->window->getSize().y);


      //  game->window->setView(viewe);


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
