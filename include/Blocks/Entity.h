//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_ENTITY_H
#define SFML_GAME_ENTITY_H

#include "SFML/Graphics.hpp"
#include <memory>


struct Positions
{
    float x;
    float y;
    int width;
    int height;
    float xCollision;
    float yCollsion;
    float xCollsionWidth;
    float yCollsionHeight;
    Positions & operator =( const Positions & right );
};

class Entity
{
protected:

public:
    Positions positions;
    Entity()= delete;
    Entity(const float cX, const float cY, const int cWidth, const int cHeight);
    virtual ~Entity();
    virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
    virtual void update(const float dt)=0;
    //virtual void input(std::shared_ptr<sf::Event> event)=0;
};

#endif //SFML_GAME_ENTITY_H
