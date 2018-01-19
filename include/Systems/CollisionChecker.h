//
// Created by Streaming on 2017-12-28.
//

#ifndef SFML_GAME_COLLISIONCHECKER_H
#define SFML_GAME_COLLISIONCHECKER_H

#include <memory>
#include "Blocks/Entity.h"
class CollisionChecker
{
public:
    bool checkAABB(std::shared_ptr<Entity> left, std::shared_ptr<Dynamic> right);
};


#endif //SFML_GAME_COLLISIONCHECKER_H
