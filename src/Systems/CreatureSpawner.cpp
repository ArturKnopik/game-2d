//
// Created by Root on 06.01.2018.
//

#include "Systems/CreatureSpawner.h"
#include <iostream>

int CreatureSpawner::idCounter=0;

void CreatureSpawner::drawTime(sf::Time time)
{
        std::cout<<"Call restart: "<<i<<" : "<<currenttime.asMilliseconds()<<std::endl;
}

void CreatureSpawner::init(std::vector<std::shared_ptr<Block>> &vector)
{
    creatureVector=&vector;
    idCounter++;
    thisID=idCounter;
    currenttime=clock.restart();

}


void CreatureSpawner::spawnCreature(sf::Time time)
{
    for(int i=0; i<creatureVector->size(); i++)
    {
        if((*creatureVector)[i]->creatureID()==thisID)
        {
            currenttime=clock.restart();
            resteTimer=true;
            return;
        }
    }

    if(resteTimer)
    {
        currenttime=clock.restart();
        resteTimer= false;
    }
    else
    {
        currenttime = clock.getElapsedTime();
    }

    if( currenttime.asSeconds() >= time.asSeconds())
    {
        std::shared_ptr<Block> tempBlock = std::make_shared<Block>(300+((rand() % 400)-200), 300+((rand() % 400)-200), 60, 60, sf::Color::Yellow);
        tempBlock->setID(thisID);
        creatureVector->push_back(tempBlock);
        drawTime(time);
        currenttime=clock.restart();
        resteTimer= true;
    }
}

void CreatureSpawner::spawnCreatureDeltaTime(float timeToWait, float dt)
{
    for(int i=0; i<creatureVector->size(); i++)
    {
        if((*creatureVector)[i]->creatureID()==thisID)
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
        std::shared_ptr<Block> tempBlock = std::make_shared<Block>(300+((rand() % 400)-200), 300+((rand() % 400)-200), 20, 20, sf::Color::Yellow);
        tempBlock->setID(thisID);
        creatureVector->push_back(tempBlock);
        std::cout<<"Current time: "<<currentTimeDT<<std::endl;
        currentTimeDT=0;
        std::cout<<"Current time: "<<currentTimeDT<<std::endl;
        resteTimer= true;
    }
}
