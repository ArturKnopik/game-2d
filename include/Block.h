//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_BLOCK_H
#define SFML_GAME_BLOCK_H

#include "Entity.h"

class Block :
        public Entity
{
private:
    sf::RectangleShape boxRect;
    sf::RectangleShape colisionRect;
    bool colisionAble=false;
    sf::RenderWindow *window;

public:
    //Block();
    Block(float x, float y, int width, int height, bool colisonAble, sf::RenderWindow * window);
    Block(float x, float y, int width, int height, float xCollision, float yCollision,
          int collisionWidth, int collisionHeight , bool colisonAble, sf::RenderWindow * window);
    ~Block();
    //Positions positions;
    void draw();
    void update(const float dt);
    void input();
};

#endif //SFML_GAME_BLOCK_H
