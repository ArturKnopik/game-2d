//
// Created by Streaming on 2017-12-13.
//

#include <Blocks/Water.h>
#include <Blocks/RockArea.h>
#include <Blocks/SimpeHouse1.h>
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"

PlayState::~PlayState() {
}

void PlayState::draw() {
    std::vector<std::shared_ptr<Entity>>::reverse_iterator iter;
    for (iter = mapEntity.rbegin(); iter != mapEntity.rend(); iter++) {
        if ((*iter)->getPositions().x - player->getPositions().x < 800 &&
            (*iter)->getPositions().x - player->getPositions().x > -800 &&
            (*iter)->getPositions().y - player->getPositions().y < 400 &&
            (*iter)->getPositions().y - player->getPositions().y > -400) {

            (*iter)->draw(game->window);
        }
    }

    ch.mouseCheckerWitchEntity(mapEntity, game->window);
    ch.drawGrid(mapEntity, game->window);
}

void PlayState::update(const float dt) {
    system("CLS");

    ch.getMapCollisionGridOnVisibleArea(mapEntity);
    viewe.setCenter(player->getOldPositions().x, player->getOldPositions().y);
    game->window->setView(viewe);
    ch.checkEntityInhArray(mapEntity);

    cSpawner->spawnCreatureDeltaTime(dt);

    std::vector<std::shared_ptr<Entity>>::iterator iter;
    for (iter = mapEntity.begin(); iter != mapEntity.end(); iter++) {

        (*iter)->update(dt);
    }
}

void PlayState::input() {
    player->input(event);
    while (this->game->window->pollEvent(*event.get())) {
        switch (event->type) {
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

PlayState::PlayState(std::shared_ptr<Game> game) {
    event = std::make_shared<sf::Event>();

    player = std::make_shared<Player>(250, 300, 32, 32, 0.0001);


    this->game = game;
    viewe.setSize(game->window->getSize().x, game->window->getSize().y);

    game->window->setView(viewe);

    mapEntity.push_back(player);
    cSpawner = std::make_shared<CreatureSpawner>(250, 200, mapEntity, RAT, 4000000);
    mapEntity.push_back(std::make_shared<SimpeHouse1>(340, 200, 96, 96));
    mapEntity.push_back(std::make_shared<Water>(132, 132, 32, 32, CAN_BE_ANIMATED, NW));
    mapEntity.push_back(std::make_shared<Water>(164, 132, 32, 32, CAN_BE_ANIMATED, N));
    mapEntity.push_back(std::make_shared<Water>(196, 132, 32, 32, CAN_BE_ANIMATED, NE));
    /*
    mapEntity.push_back(std::make_shared<Water>(132, 164, 32, 32, CAN_BE_ANIMATED, W));
    mapEntity.push_back(std::make_shared<Water>(164, 164, 32, 32, CAN_BE_ANIMATED, C));
    mapEntity.push_back(std::make_shared<Water>(196, 164, 32, 32, CAN_BE_ANIMATED, E));
    mapEntity.push_back(std::make_shared<Water>(132, 196, 32, 32, CAN_BE_ANIMATED, SW));
    mapEntity.push_back(std::make_shared<Water>(164, 196, 32, 32, CAN_BE_ANIMATED, S));
    mapEntity.push_back(std::make_shared<Water>(196, 196, 32, 32, CAN_BE_ANIMATED, SE));
     */
    mapEntity.push_back(std::make_shared<Ground>(64, 64, 32, 32, NO_COLLISION, C));
    mapEntity.push_back(std::make_shared<Ground>(96, 64, 32, 32, NO_COLLISION, C));
    mapEntity.push_back(std::make_shared<Ground>(64, 96, 32, 32, NO_COLLISION, C));
    mapEntity.push_back(std::make_shared<Ground>(96, 96, 32, 32, NO_COLLISION, C));
    mapEntity.push_back(std::make_shared<RockArea>(300, 132, 32, 32, C));
    mapEntity.push_back(std::make_shared<RockArea>(300, 164, 32, 32, C));
    /*
    mapEntity.push_back(std::make_shared<RockArea>(300, 196, 32, 32, C));
    mapEntity.push_back(std::make_shared<RockArea>(300, 228, 32, 32, C));
    mapEntity.push_back(std::make_shared<RockArea>(300, 260, 32, 32, C));

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            mapEntity.push_back(std::make_shared<Ground>(i * 32, j * 32, 32, 32, NO_COLLISION, C));
        }
    }

*/
}
