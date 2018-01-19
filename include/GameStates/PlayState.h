//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_PLAYSTATE_H
#define SFML_GAME_PLAYSTATE_H

#include <Blocks/Player.h>
#include <Blocks/SimpleEnemy.h>
#include "GameState.h"
#include "Buttoms/Button.h"
#include "Blocks/Block.h"
#include "Systems/CollisionChecker.h"
#include "Systems/CreatureSpawner.h"
class PlayState : public GameState
{
private:
    std::vector <std::shared_ptr<Block>> creatureVector;
    std::shared_ptr<sf::Event> event;
    std::shared_ptr<SimpleEnemy> simpleEnemy;
    CreatureSpawner cChecker;
    CreatureSpawner cChecker1;
    CollisionChecker ch;
    std::shared_ptr<Player> player;
public:
    ~PlayState();
    void draw(const float dt);
    void update(const float dt);
    void input();
    PlayState(std::shared_ptr<Game> game);

};


#endif //SFML_GAME_PLAYSTATE_H
