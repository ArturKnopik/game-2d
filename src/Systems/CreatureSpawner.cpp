//
// Created by Root on 06.01.2018.
//

#include "Systems/CreatureSpawner.h"
#include <iostream>
#include <Blocks/Rat.h>

int CreatureSpawner::idCounter=0;

void CreatureSpawner::spawnCreatureDeltaTime(float dt)
{
    for(int i=0; i<creatureVector->size(); i++)
    {
        if((*creatureVector)[i]->getEntityID()==thisID)
        {
            currentTimeDT=0;
            resteTimer=true;
            return;
        }
    }

    if(resteTimer)
    {
        currentTimeDT=0;
        resteTimer= false;
    }
    else
    {
        currentTimeDT = currentTimeDT+dt;
    }

    if( currentTimeDT >= timeToWait)
    {
        switch(typeOfCreatureToSpawn)
        {
            case RAT:
                //std::shared_ptr<Creature> tempCreature = std::make_shared<Rat>(x+((rand() % 400)-200), y+((rand() % 400)-200), 32, 32, 0.00002);
                std::shared_ptr<Creature> tempCreature = std::make_shared<Rat>(x, y, 32, 32, 0.00002);

                tempCreature->setEntityID(thisID);
                creatureVector->push_back(tempCreature);
                currentTimeDT=0;
                resteTimer= true;
                break;
        }

    }
}

CreatureSpawner::CreatureSpawner(float cX, float cY, std::vector<std::shared_ptr<Entity>> &vector,
                                 CreatureType cType, float cTimeToWait)
:x(cX), y(cY), timeToWait(cTimeToWait), typeOfCreatureToSpawn(cType)
{
    creatureVector=&vector;
    idCounter++;
    thisID=idCounter;
    switch(typeOfCreatureToSpawn)
    {
        case RAT:
            //std::shared_ptr<Creature> tempCreature = std::make_shared<Rat>(x+((rand() % 400)-200), y+((rand() % 400)-200), 32, 32, 0.00002);
            std::shared_ptr<Creature> tempCreature = std::make_shared<Rat>(x, y, 32, 32, 0.00002);

            tempCreature->setEntityID(thisID);
            creatureVector->push_back(tempCreature);
            currentTimeDT=0;
            resteTimer= true;
            break;
    }
}

void CreatureSpawner::setCreatureToSpawn(CreatureType creature)
{
    typeOfCreatureToSpawn=creature;
}

CreatureType CreatureSpawner::getCreatureToSpawn()
{
    return typeOfCreatureToSpawn;
}
