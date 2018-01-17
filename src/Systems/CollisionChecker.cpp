//
// Created by Streaming on 2017-12-28.
//

#include "Systems/CollisionChecker.h"

bool CollisionChecker::checkAABB(std::shared_ptr<Block> left, std::shared_ptr<Block> right)
{
    if (left->positions.x < right->positions.x + right->positions.width &&
        left->positions.x + left->positions.width > right->positions.x &&
        left->positions.y < left->positions.y + right->positions.height &&
        left->positions.height + left->positions.y > right->positions.y)
    {
       // left->setIsCollidet(true);
        //right->setIsCollidet(true);
        return true;
    }
    else
    {
        //left->setIsCollidet(false);
        //right->setIsCollidet(false);
        return false;
    }

}
