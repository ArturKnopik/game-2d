//
// Created by Streaming on 2017-12-13.
//

#include "Block.h"

Block::Block(float x, float y, int width, int height, bool colisonAble, sf::RenderWindow * window)
{
    this->window = window;
    positions.x = x;
    positions.y = y;
    positions.width = width;
    positions.height = height;
    positions.xCollision = x;
    positions.yCollision = y;
    positions.collisionWidth = width;
    positions.collisionHeight = height;
    boxRect.setFillColor(sf::Color(255, 255, 255, 255));
    colisionRect.setFillColor(sf::Color(255, 0, 0, 150));
}

Block::Block(float x, float y, int width, int height, float xCollision, float yCollision,
             int collisionWidth, int collisionHeight, bool colisonAble, sf::RenderWindow * window)
{
    this->window = window;
    positions.x = x;
    positions.y = y;
    positions.width = width;
    positions.height = height;
    positions.xCollision = xCollision;
    positions.yCollision = yCollision;
    positions.collisionWidth = collisionWidth;
    positions.collisionHeight = collisionHeight;
    boxRect.setFillColor(sf::Color(255, 255, 255, 255));
    colisionRect.setFillColor(sf::Color(255, 0, 0, 150));
}


Block::~Block()
{
}

void Block::draw()
{
    window->draw(boxRect);
    window->draw(colisionRect);
}

void Block::update(const float dt)
{
    boxRect.setPosition(sf::Vector2f(positions.x, positions.y));
    boxRect.setSize(sf::Vector2f(positions.width, positions.height));
    colisionRect.setPosition(sf::Vector2f(positions.xCollision, positions.yCollision));
    colisionRect.setSize(sf::Vector2f(positions.collisionWidth, positions.collisionHeight));
}

void Block::input()
{
}
