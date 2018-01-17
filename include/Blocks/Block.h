//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_BLOCK_H
#define SFML_GAME_BLOCK_H

#include "Entity.h"
#include <string>
class Block :
        public Entity
{
private:
    sf::RectangleShape boxRect;
    sf::RectangleShape colisionRect;
    bool colisionAble=false;
    bool isCollidet=false;
    std::string imageURL;
    std::shared_ptr<sf::Event> event ;
    sf::Color color;
    int id;
public:
    Block(float cX,float cY, int cWidth, int cHeight, sf::Color cColor);
    Block(float cX,float cY, int cWidth, int cHeight, std::string urlToImage);
    ~Block();
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void setID(int i);
    void update(const float dt);
    void input(std::shared_ptr<sf::Event> event);
    void setIsCollidet(bool isCollidet);
    bool getIsCollidet();
    int creatureID();
};

#endif //SFML_GAME_BLOCK_H
