//
// Created by Streaming on 2017-12-28.
//

#ifndef SFML_GAME_COLLISIONCHECKER_H
#define SFML_GAME_COLLISIONCHECKER_H

#include <memory>
#include <vector>
#include <Blocks/Dynamic.h>

class CollisionChecker {
    int mapGridX, mapGridY;
    bool gridMap[320][180];
public:
    CollisionChecker();

    void init(std::vector<std::shared_ptr<Entity>> &mapEntity);

    void
    mouseCheckerWitchEntity(std::vector<std::shared_ptr<Entity>> &mapEntity, std::shared_ptr<sf::RenderWindow> &window);

    bool checkAABB(std::shared_ptr<Entity> &left, std::shared_ptr<Entity> &right);

    void checkEntityInhArray(std::vector<std::shared_ptr<Entity>> &mapEntity);

    void getMapCollisionGridOnVisibleArea(std::vector<std::shared_ptr<Entity>> &mapEntity);

    void drawGrid(std::vector<std::shared_ptr<Entity>> &mapEntity, std::shared_ptr<sf::RenderWindow> &window);

};


#endif //SFML_GAME_COLLISIONCHECKER_H
