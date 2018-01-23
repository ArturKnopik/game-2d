//
// Created by Streaming on 2017-12-13.
//

#include "Blocks/Block.h"

Block::Block(float cX,float cY, int cWidth, int cHeight, sf::Color cColor )
    :color(cColor), Entity(cX, cY, cWidth, cHeight)
{
    positions.x=cX;
    positions.y=cY;
    positions.width=cWidth;
    positions.height=cHeight;
    boxRect.setPosition(positions.x, positions.y);
    boxRect.setSize(sf::Vector2f(positions.width, positions.height));
    boxRect.setFillColor(color);
    boxRect.setOutlineColor(sf::Color::Red);
}


Block::~Block()
{
}

void Block::draw(std::shared_ptr<sf::RenderWindow> window)
{
    if(getIsCollidet())
    {
        boxRect.setOutlineThickness(2);
    }
    else
    {
        boxRect.setOutlineThickness(0);
    }
    window->draw(boxRect);
}

void Block::update(const float dt)
{

}

void Block::input(std::shared_ptr<sf::Event> event) {

}

bool Block::getIsCollidet()
{
    return isCollidet;
}

void Block::setIsCollidet(bool isCollidet)
{
    this->isCollidet = isCollidet;
}

Block::Block(const float cX, const float cY,const  int cWidth,const int cHeight, const std::string urlToImage)
        :imageURL(urlToImage), Entity(cX, cY, cWidth, cHeight)
{
    positions.x=cX;
    positions.y=cY;
    positions.width=cWidth;
    positions.height=cHeight;
    boxRect.setPosition(positions.x, positions.y);
    boxRect.setSize(sf::Vector2f(positions.width, positions.height));
    boxRect.setFillColor(color);
    boxRect.setOutlineColor(sf::Color::Red);
}

void Block::setEntityID(int i)
{
  this->id=i;
}

int Block::getEntityID()
{
    return id;
}


