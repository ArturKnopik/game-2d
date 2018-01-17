//
// Created by Root on 06.01.2018.
//

#ifndef SFML_GAME_CREATURESPAWNER_H
#define SFML_GAME_CREATURESPAWNER_H

#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include <vector>
#include <memory>
#include "Blocks/Block.h"
#include <cstdlib>

class CreatureSpawner {
private:
    sf::Clock clock;
    sf::Time currenttime;
    float currentTimeDT=0;
    //float totalTime;
    static int idCounter;
    int thisID;
    int i=0;
    bool isCreatureLive=false;
    bool resteTimer=true;
    std::vector<std::shared_ptr<Block>> *creatureVector;
public:
    void drawTime(sf::Time time);
    void spawnCreature(sf::Time time);
    void init(std::vector<std::shared_ptr<Block>> &vector);
    void spawnCreatureDeltaTime(float timeToWait, float dt);



};


#endif //SFML_GAME_CREATURESPAWNER_H
