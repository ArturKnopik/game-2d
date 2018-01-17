//
// Created by Streaming on 2017-12-28.
//

#ifndef SFML_GAME_COLLISIONCHECKER_H
#define SFML_GAME_COLLISIONCHECKER_H

#include <memory>
#include "Blocks/Block.h"
class CollisionChecker
{
public:
    bool checkAABB(std::shared_ptr<Block> left, std::shared_ptr<Block> right);
};


#endif //SFML_GAME_COLLISIONCHECKER_H
