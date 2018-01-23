//
// Created by Streaming on 2017-12-28.
//


#include "Systems/CollisionChecker.h"

bool CollisionChecker::checkAABB(std::shared_ptr<Entity> & left, std::shared_ptr<Entity> & right)
{
    if (left->positions.x < right->positions.x + right->positions.width &&
        left->positions.x + left->positions.width > right->positions.x &&
        left->positions.y < right->positions.y + right->positions.height &&
        left->positions.height + left->positions.y > right->positions.y)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void CollisionChecker::checkEntityInhArray(std::vector<std::shared_ptr<Entity>> & mapEntity)
{
    //checkAABB(mapEntity[0], entity);

    for(int i=0; i<mapEntity.size();i++)
    {
        for (int j = 0; j < mapEntity.size(); j++)
        {
            if(i!=j)
            {
               // std::cout<<"Collision check for:"<<i<<" and "<<j<<std::endl;
                if (mapEntity[i]->isCollisionAble() && (mapEntity[j]->isCollisionAble()))
                {
                    if (checkAABB(mapEntity[i], mapEntity[j]))
                    {
                        std::cout<<"Collision detected for:"<<i<<" and "<<j<<std::endl;
                        mapEntity[i]->setCollisionStatus(IS_COLLIDET);
                        mapEntity[j]->setCollisionStatus(IS_COLLIDET);
                        break;
                    }
                    else
                    {
                        mapEntity[j]->setCollisionStatus(NO_COLLISION);
                        mapEntity[i]->setCollisionStatus(NO_COLLISION);
                    }
                }
            }
        }
    }
}


