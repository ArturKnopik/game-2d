//
// Created by Streaming on 2017-12-28.
//

#include <Blocks/Dynamic.h>
#include "Systems/CollisionChecker.h"

bool CollisionChecker::checkAABB(std::shared_ptr<Entity> left, std::shared_ptr<Dynamic> right)
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
