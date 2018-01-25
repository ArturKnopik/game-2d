//
// Created by Streaming on 2017-12-28.
//


#include "Systems/CollisionChecker.h"

CollisionChecker::CollisionChecker() {
    for (int i = 0; i < 320; i++) {
        for (int j = 0; j < 180; j++) {
            gridMap[i][j] = false;
        }
    }
}

bool CollisionChecker::checkAABB(std::shared_ptr<Entity> &left, std::shared_ptr<Entity> &right) {
    if (left->positions.x < right->positions.x + right->positions.width &&
        left->positions.x + left->positions.width > right->positions.x &&
        left->positions.y < right->positions.y + right->positions.height &&
        left->positions.height + left->positions.y > right->positions.y) {
        return true;
    } else {
        return false;
    }

}

void CollisionChecker::checkEntityInhArray(std::vector<std::shared_ptr<Entity>> &mapEntity) {
    //checkAABB(mapEntity[0], entity);

    for (int i = 0; i < mapEntity.size(); i++) {
        for (int j = 0; j < mapEntity.size(); j++) {
            if (i != j) {
                if (mapEntity[i]->isCollisionAble() && (mapEntity[j]->isCollisionAble())) {
                    if (checkAABB(mapEntity[i], mapEntity[j])) {
                        mapEntity[i]->setCollisionStatus(IS_COLLIDET);
                        break;
                    } else {
                        mapEntity[i]->setCollisionStatus(NO_COLLISION);
                    }
                }
            }
        }
    }
}

void CollisionChecker::mouseCheckerWitchEntity(std::vector<std::shared_ptr<Entity>> &mapEntity,
                                               std::shared_ptr<sf::RenderWindow> &window) {
    sf::Vector2f mouse_pos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    for (int i = 0; i < mapEntity.size(); i++) {
        if (mouse_pos.x > mapEntity[i]->positions.x &&
            mouse_pos.x < mapEntity[i]->positions.x + mapEntity[i]->positions.width &&
            mouse_pos.y > mapEntity[i]->positions.y &&
            mouse_pos.y < mapEntity[i]->positions.y + mapEntity[i]->positions.height) {
            if (mapEntity[i]->getTypeOfEntity() == CREATURE || mapEntity[i]->getTypeOfEntity() == PLAYER) {
                std::cout << "Mouses on Entity: " << sf::Mouse::getPosition(*window).x << " : "
                          << sf::Mouse::getPosition(*window).y << std::endl;
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f(mapEntity[i]->positions.width, mapEntity[i]->positions.height));
                rect.setFillColor(sf::Color(0, 0, 0, 0));
                rect.setOutlineThickness(2);
                rect.setOutlineColor(sf::Color::Red);

                rect.setPosition(mapEntity[i]->positions.x, mapEntity[i]->positions.y);
                window->draw(rect);
            }
        }
    }
    std::cout << "Mouse Positions: " << sf::Mouse::getPosition(*window).x << " : " << sf::Mouse::getPosition(*window).y
              << std::endl;

}

void CollisionChecker::getMapCollisionGridOnVisibleArea(std::vector<std::shared_ptr<Entity>> & mapEntity) {
    //restarting grid
    for (int i = 0; i < 320; i++) {
        for (int j = 0; j < 180; j++) {
            gridMap[i][j] = false;
        }
    }
    for (int i = 0; i < mapEntity.size(); i++) {
        if (mapEntity[i]->positions.x > mapEntity[0]->positions.x - 100 &&
            mapEntity[i]->positions.x < mapEntity[0]->positions.x + 100 &&
            mapEntity[i]->positions.y < mapEntity[0]->positions.x + 100 &&
            mapEntity[i]->positions.y > mapEntity[0]->positions.x - 100) {


            int startX, endX, startY, endY;
            startX = static_cast<int>(mapEntity[i]->positions.x+mapEntity[0]->positions.x) / 4;
            endX = static_cast<int>(mapEntity[i]->positions.x + mapEntity[i]->positions.width+mapEntity[0]->positions.x) / 4;
            startY = static_cast<int>(mapEntity[i]->positions.y+mapEntity[0]->positions.y) / 4;
            endY = static_cast<int>(mapEntity[i]->positions.y + mapEntity[i]->positions.height-mapEntity[0]->positions.y) / 4;
            if (startX < 0) {
                startX = 0;
            }
            if (startY < 0) {
                startY = 0;
            }
            if (endX > 319) {
                endX = 319;
            }
            if (endY > 179) {
                endY = 179;
            }
            for (int j = startX; j <= endX; j++) {
                for (int k = startY; k <= endY; k++) {

                    gridMap[j][k] = true;
                    // std::cout<<" x:y - "<<startX<<":"<<endX<< "    "<<startY<<":"<<endY<<std::endl;
                }

            }
        }
    }
}

void CollisionChecker::drawGrid(std::vector<std::shared_ptr<Entity>> & mapEntity, std::shared_ptr<sf::RenderWindow> &window) {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(4, 4));
    for (int i = 0; i < 320; i++) {
        for (int j = 0; j < 180; j++) {
            if (gridMap[i][j] == true) {
                rect.setPosition((mapEntity[0]->positions.x-600)+(i * 4),(mapEntity[0]->positions.y-300)+ (j * 4));
                rect.setFillColor(sf::Color(250, 0, 0, 100));
                window->draw(rect);
            }
            else
            {
                rect.setPosition((mapEntity[0]->positions.x-600)+(i * 4),(mapEntity[0]->positions.y-300)+ (j * 4));
                rect.setFillColor(sf::Color(0, 250, 0, 100));
                window->draw(rect);

            }
        }
    }
}


