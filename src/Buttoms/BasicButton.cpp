//
// Created by Streaming on 2017-12-13.
//

#include "Buttoms/BasicButton.h"




BasicButton::BasicButton(std::string text, float x, float y, float width, float height, int textSize, sf::Texture *)
{
    positions.x = x;
    positions.y = y;
    positions.width = width;
    positions.height = height;
    positions.textSize = textSize;
    this->text = text;
    this->texture = texture;
    font.loadFromFile("resource/font/arial.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(textSize);
}

BasicButton::BasicButton(std::string text, float x, float y, float width, float height, int textSize, sf::Color outerColor, sf::Color innerColor)
{
    positions.x = x;
    positions.y = y;
    positions.width = width;
    positions.height = height;
    positions.textSize = textSize;
    this->innerColor = innerColor;
    this->outerColor = outerColor;
    font.loadFromFile("resource/font/arial.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    this->text = text;
    buttonText.setCharacterSize(textSize);
    textX = positions.x + ((positions.width - buttonText.getLocalBounds().width) / 2);
    textY = positions.y + ((positions.height - buttonText.getLocalBounds().height) / 2)- buttonText.getLocalBounds().height/3;
}

BasicButton::~BasicButton()
{
}

void BasicButton::onClick()
{

}

void BasicButton::noActived()
{
    buttonState = false;
}

void BasicButton::actived()
{
    buttonState = true;
}

void BasicButton::draw(std::shared_ptr<sf::RenderWindow> window)
{

    if (buttonState)
    {
        rect.setPosition(sf::Vector2f(positions.x - 2, positions.y - 2));
        rect.setSize(sf::Vector2f(positions.width + 4, positions.height + 4));
        rect.setFillColor(innerColor);
        window->draw(rect);

    }

    rect.setPosition(sf::Vector2f(positions.x, positions.y));
    rect.setSize(sf::Vector2f(positions.width, positions.height));
    rect.setFillColor(outerColor);

    //float tempX=((positions.width-buttonText.getGlobalBounds().width)/2)
    buttonText.setPosition(sf::Vector2f(textX , textY));
    buttonText.setFillColor(innerColor);
    // std::cout << "fix: " << ((positions.height - buttonText.getGlobalBounds().height) / 2) << std::endl;

    /*
    menuText.setCharacterSize(30);
    menuText.setPosition(sf::Vector2f(120, 300));
    menuText.setString("Quit!");
    menuText.setFillColor(sf::Color::Black);
    */

    window->draw(rect);
    window->draw(buttonText);

}

bool BasicButton::isActived()
{
    return buttonState;
}

