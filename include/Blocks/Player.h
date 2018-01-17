//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_PLAYER_H
#define SFML_GAME_PLAYER_H

#include "Blocks/Dynamic.h"

struct SpriteData
{
    float timeToNextFrame=300000; //1000000 = 1s
    float currentTime=0;
    float numbersOfFrame=2;
    float currentFrame=0;
    Directory imageDir=DOWN;
    int spriteX=0;
    int spriteY=0;
    int spriteWidth=32;
    int spriteHeight=32;
};

class Player
        :public Dynamic
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    SpriteData spriteData;
    float idleTime; //1000000 = 1s
public:
    Player()=delete;
    Player(float cX, float cY, int cWidth, int cHeight, float cSpeed);
    void draw(std::shared_ptr<sf::RenderWindow> window) override;
    void update(const float dt) override;
    void input(std::shared_ptr<sf::Event> event);
    void setCustomSpriteData(const float timeToNextFrame,const float numbersOfFrame,const Directory imageDir,const int spriteX,const int spriteY,const int spriteWidth,const int spriteHeight);



};


#endif //SFML_GAME_PLAYER_H
