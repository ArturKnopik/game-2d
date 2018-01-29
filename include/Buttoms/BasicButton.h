//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_BASICBUTTON_H
#define SFML_GAME_BASICBUTTON_H


#include "Button.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class BasicButton :
        public Button
{
private:
    float textX;
    float textY;
    struct Positions
    {
        float x;
        float y;
        float width;
        float height;
        int textSize;
    };
    std::string text;
    bool buttonState=true;
    sf::Texture * texture;
    sf::Color outerColor;
    sf::Color innerColor;
    sf::Font font;
    sf::Text buttonText;
    sf::RectangleShape rect;

public:


    Positions positions;
    BasicButton(std::string text, float x, float y, float width, float height, int textSize, sf::Texture *);
    BasicButton(std::string text, float x, float y, float width, float height, int textSize, sf::Color color, sf::Color innerColor);

    ~BasicButton();
    void onClick();
    void noActived();
    void actived();
    void draw(std::shared_ptr<sf::RenderWindow> window);
    bool isActived();

};
#endif //SFML_GAME_BASICBUTTON_H
