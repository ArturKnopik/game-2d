//
// Created by Root on 06.01.2018.
//

#ifndef SFML_GAME_CREATURESPAWNER_H
#define SFML_GAME_CREATURESPAWNER_H

#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include <vector>
#include <memory>
#include <cstdlib>
#include <Blocks/Creature.h>
enum CreatureType
{
    RAT
};
class CreatureSpawner {
private:

    float currentTimeDT=0;
    static int idCounter;
    int thisID;
    bool resteTimer=true;
    std::vector<std::shared_ptr<Entity>> *creatureVector;
    float x;
    float y;
    float timeToWait;
    CreatureType typeOfCreatureToSpawn;
public:
    CreatureSpawner()=delete;
    CreatureSpawner(float cX, float cY, std::vector<std::shared_ptr<Entity>> &vector, CreatureType cType, float cTimeToWait);
    void spawnCreatureDeltaTime(float dt);
    void setCreatureToSpawn(CreatureType creature);
    CreatureType getCreatureToSpawn();


};


#endif //SFML_GAME_CREATURESPAWNER_H
