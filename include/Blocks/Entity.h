//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_ENTITY_H
#define SFML_GAME_ENTITY_H

#include "SFML/Graphics.hpp"
#include <memory>
#include <iostream>


struct Positions
{
    float x=0;
    float y=0;
    int width=32;
    int height=32;
    float xCollision;
    float yCollsion;
    float xCollsionWidth;
    float yCollsionHeight;
    Positions & operator =( const Positions & right );
};

class Entity
{
public:
    Positions positions;
    Entity()= delete;
    Entity( float cX,  float cY,  int cWidth,  int cHeight);
    virtual ~Entity();
    virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
    virtual void update(const float dt)=0;
    //virtual void input(std::shared_ptr<sf::Event> event)=0;
};

#endif //SFML_GAME_ENTITY_H
