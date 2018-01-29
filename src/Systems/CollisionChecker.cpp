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
    if (left->getPositions().x < right->getPositions().x + right->getSize().width &&
        left->getPositions().x + left->getSize().width > right->getPositions().x &&
        left->getPositions().y < right->getPositions().y + right->getSize().height &&
        left->getSize().height + left->getPositions().y > right->getPositions().y) {
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
        if (mouse_pos.x > mapEntity[i]->getPositions().x &&
            mouse_pos.x < mapEntity[i]->getPositions().x + mapEntity[i]->getSize().width &&
            mouse_pos.y > mapEntity[i]->getPositions().y &&
            mouse_pos.y < mapEntity[i]->getPositions().y + mapEntity[i]->getSize().height) {
            if (mapEntity[i]->getTypeOfEntity() == CREATURE || mapEntity[i]->getTypeOfEntity() == PLAYER) {
                sf::RectangleShape rect;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(mapEntity[i]->getSize().width, mapEntity[i]->getSize().height));
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineThickness(2);
                    rect.setOutlineColor(sf::Color::Red);
                    rect.setPosition(mapEntity[i]->getPositions().x, mapEntity[i]->getPositions().y);
                    window->draw(rect);

                }
            }
        }
    }
    std::cout << "Mouse Positions: " << sf::Mouse::getPosition(*window).x << " : " << sf::Mouse::getPosition(*window).y
              << std::endl;

}

void CollisionChecker::getMapCollisionGridOnVisibleArea(std::vector<std::shared_ptr<Entity>> &mapEntity) {
    //restarting grid
    for (int i = 0; i < 320; i++) {
        for (int j = 0; j < 180; j++) {
            gridMap[i][j] = false;
        }
    }
    for (int i = 0; i < mapEntity.size(); i++) {
        if (mapEntity[i]->getPositions().x > mapEntity[0]->getPositions().x - 600 &&
            mapEntity[i]->getPositions().x < mapEntity[0]->getPositions().x + 600 &&
            mapEntity[i]->getPositions().y < mapEntity[0]->getPositions().y + 300 &&
            mapEntity[i]->getPositions().y > mapEntity[0]->getPositions().y - 300 &
            mapEntity[i]->isCollisionAble() != CAN_BE_COLLIDET) {

            int startX, endX, startY, endY;
            startX = (static_cast<int>(mapEntity[i]->getPositions().x-(mapEntity[0]->getPositions().x-640) ) / 4) - 1;
            endX = static_cast<int>(mapEntity[i]->getPositions().x + mapEntity[i]->getSize().width -(mapEntity[0]->getPositions().x-640)) / 4;
            startY = (static_cast<int>(mapEntity[i]->getPositions().y-(mapEntity[0]->getPositions().y-360)) / 4) - 1;
            endY = static_cast<int>(mapEntity[i]->getPositions().y + mapEntity[i]->getSize().height -(mapEntity[0]->getPositions().y-360)) / 4;
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
                }
            }
        }
    }
}

void
CollisionChecker::drawGrid(std::vector<std::shared_ptr<Entity>> &mapEntity, std::shared_ptr<sf::RenderWindow> &window) {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(4, 4));
    for (int i = 0; i < 320; i++) {
        for (int j = 0; j < 180; j++) {
            if (gridMap[i][j] == true) {
                rect.setPosition((i * 4)+mapEntity[0]->getPositions().x-640, (j * 4)+mapEntity[0]->getPositions().y-360);
                rect.setFillColor(sf::Color(250, 0, 0, 100));
                window->draw(rect);
            }
        }
    }
}

void CollisionChecker::init(std::vector<std::shared_ptr<Entity>> &mapEntity) {

}


