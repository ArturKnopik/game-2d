//
// Created by Streaming on 2017-12-28.
//

#ifndef SFML_GAME_COLLISIONCHECKER_H
#define SFML_GAME_COLLISIONCHECKER_H

#include <memory>
#include <vector>
#include <Blocks/Dynamic.h>

class CollisionChecker
{
public:
    CollisionChecker()= default;
    bool checkAABB(std::shared_ptr<Entity> & left, std::shared_ptr<Dynamic> & right);
    void checkEntityWitchArray( std::vector<std::shared_ptr<Entity>> & mapEntity,
                                std::shared_ptr<Dynamic> entity);
};


#endif //SFML_GAME_COLLISIONCHECKER_H
