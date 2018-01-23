//
// Created by Streaming on 2017-12-13.
//
#include "GameStates/MenuState.h"

MenuState::MenuState(std::shared_ptr<Game> game)
{
    this->game = game;
    font.loadFromFile("resource/font/arial.ttf");
    sf::Text tempText("hello", font);
    menuText = tempText;
    menuButtonElements.push_back(new BasicButton("Game", 100, 100, 600, 50, 50, sf::Color(0,100,255,200), sf::Color(100,255,0,180)));
    menuButtonElements.push_back(new BasicButton("About", 100, 200, 600, 50, 50, sf::Color(0, 0, 255, 200), sf::Color(0, 255, 0, 200)));
    menuButtonElements.push_back(new BasicButton("Quit", 100, 300, 600, 50, 50, sf::Color(0, 100, 155, 200), sf::Color::Red));
    std::cout << "MenuState::MenuState  |  ";
}


void MenuState::input()
{
    sf::Event event;

    while (game->window->pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
                game->window->close();
                break;

                /* Change Between game states */
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    game->window->close();
                }
                if (event.key.code == sf::Keyboard::Return&& menuSwitch==0)
                {
                    loadgame();
                }
                if (event.key.code == sf::Keyboard::Return&& menuSwitch == 1)
                {
                    std::cout << "About" << std::endl;
                }
                if (event.key.code == sf::Keyboard::Return&& menuSwitch == 2)
                {
                    game->window->close();
                }

                if (event.key.code == sf::Keyboard::Up)
                {
                    if(menuSwitch>=1)
                    {
                        menuSwitch--;
                    }
                    else
                    {
                        menuSwitch = 2;
                    }
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    if(menuSwitch<=1)
                    {
                        menuSwitch++;
                    }
                    else
                    {
                        menuSwitch = 0;
                    }
                }
                break;


        }
    }

}
/*
MenuState::~MenuState()
{
}
*/

void MenuState::update(const float dt)
{

    switch (menuSwitch)
    {
        case 0:
            for (int i=0; i < menuButtonElements.size(); i++)
            {
                if (i == menuSwitch)
                {
                    menuButtonElements[i]->actived();
                }
                else
                {
                    menuButtonElements[i]->noActived();
                }
            }

            break;
        case 1:
            for (int i=0; i < menuButtonElements.size(); i++)
            {
                if (i == menuSwitch)
                {
                    menuButtonElements[i]->actived();
                }
                else
                {
                    menuButtonElements[i]->noActived();
                }
            }
            break;
        case 2:
            for (int i=0; i < menuButtonElements.size(); i++)
            {
                if (i == menuSwitch)
                {
                    menuButtonElements[i]->actived();
                }
                else
                {
                    menuButtonElements[i]->noActived();
                }
            }
            break;
    }
}



void MenuState::draw()
{

    for (int i=0; i < menuButtonElements.size(); i++)
    {
        menuButtonElements[i]->draw(game->window);
    }

}


void MenuState::loadgame()
{
    std::cout << "MenuState::loadgame  |  ";
    game->pushState(std::shared_ptr<GameState> (new PlayState(game)));


}