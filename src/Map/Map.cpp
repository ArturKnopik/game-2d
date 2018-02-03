//
// Created by Streaming on 2018-01-23.
//

#include <Blocks/SimpeHouse1.h>
#include <Blocks/Water.h>
#include <Blocks/Ground.h>
#include <Blocks/RockArea.h>
#include "Map/Map.h"

Map::Map() {
    mapEntity.reserve(4);

}

void Map::addElement(std::shared_ptr<Entity> entity, MapLayer mapLayer) {

    switch (mapLayer) {
        case GROUND_LAYER:
            if (entity->isCollisionAble()) {
                mapEntity[GROUND_LAYER].push_back(entity);
            } else {
                collisionMapEntity[GROUND_LAYER].push_back(entity);
            }
            break;
        case GROUND_DECORATION_LAYER:
            if (entity->isCollisionAble()) {
                mapEntity[GROUND_DECORATION_LAYER].push_back(entity);
            } else {
                collisionMapEntity[GROUND_DECORATION_LAYER].push_back(entity);
            }
            break;
        case CREATURE_LAYER:
            if (entity->isCollisionAble()) {
                mapEntity[CREATURE_LAYER].push_back(entity);
            } else {
                collisionMapEntity[CREATURE_LAYER].push_back(entity);
            }
            break;
        case SKY_LAYER:
            if (entity->isCollisionAble()) {
                mapEntity[SKY_LAYER].push_back(entity);
            } else {
                collisionMapEntity[SKY_LAYER].push_back(entity);
            }
            break;
    }

}
