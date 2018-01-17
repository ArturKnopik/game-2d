//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_BUTTON_H
#define SFML_GAME_BUTTON_H
#include <memory>
#include "SFML/Graphics.hpp"
class Button
{
public:
    Button();
    ~Button();
    virtual void onClick()=0;
    virtual void noActived()=0;
    virtual void actived()=0;
    virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
    virtual bool isActived() = 0;
};



#endif //SFML_GAME_BUTTON_H
