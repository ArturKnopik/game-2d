//
// Created by Streaming on 2018-01-23.
//

#ifndef SFML_GAME_MAP_H
#define SFML_GAME_MAP_H


#include <Blocks/Entity.h>
/// Eenum where to add an object on the mapLayer arrays
enum MapLayer
{
    GROUND_LAYER=0,
    GROUND_DECORATION_LAYER=1,
    CREATURE_LAYER=2,
    SKY_LAYER=3

};
class Map
{
private:
    std::vector<std::vector<std::shared_ptr<Entity>>> mapEntity;
    std::vector<std::vector<std::shared_ptr<Entity>>> collisionMapEntity;

public:
    Map();
    /// Allow to add entity to map based of type given to function and isCollision() value
    /// \param entity std::shared_ptr<Entity>
    /// \param mapLayer - Enmu MapLayer
    void addElement(std::shared_ptr<Entity> entity,MapLayer mapLayer );
    /// Return map
    /// \return
    std::vector<std::vector<std::shared_ptr<Entity>>> getMap();
};


#endif //SFML_GAME_MAP_H
