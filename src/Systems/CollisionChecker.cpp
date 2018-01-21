//
// Created by Streaming on 2017-12-28.
//


#include "Systems/CollisionChecker.h"

bool CollisionChecker::checkAABB(std::shared_ptr<Entity> & left, std::shared_ptr<Dynamic> & right)
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

void CollisionChecker::checkEntityWitchArray(std::vector<std::shared_ptr<Entity>> & mapEntity,
                                             std::shared_ptr<Dynamic> entity)
{
    checkAABB(mapEntity[0], entity);

    for(int i=0; i<mapEntity.size();i++)
    {
       if (mapEntity[i]->isColsion())
       {
            if (checkAABB(mapEntity[i], entity))
            {
                entity->setColsion(COLLISIONTRUE);
                break;
            }
            else
            {
                entity->setColsion(COLLISIONFALSE);
            }
       }
    }

}
