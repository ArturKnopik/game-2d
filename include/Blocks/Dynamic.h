//
// Created by Root on 13.01.2018.
//

#ifndef SFML_GAME_DYNAMIC_H
#define SFML_GAME_DYNAMIC_H

#include "Blocks/Entity.h"
enum Directory
{
    UP=0,
    DOWN=1,
    LEFT=2,
    RIGHT=3
};
enum Status
{
    IDLE=0,
    MOVING=1,
    STOP=2
};

struct SpriteData
{
    int timeToNextFrame=300000; //1000000 = 1s
    int currentTime=0;
    int numbersOfFrame=2;
    int currentFrame=0;
    Directory imageDir=DOWN;
    int spriteWidth=32;
    int spriteHeight=32;
};

class Dynamic
        : public Entity
{
private:
    Status status;
    Directory dir;
    float speed;
    bool collsion=false;
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    SpriteData spriteData;
    virtual Status getStatus() const;
    void setStatus(Status status);
    Directory getDirectory() const ;
    void setDir(Directory dir);
public:
    bool isCollsion();
    void setCollsion(bool isCollsion);
    Positions oldPositions;
    Dynamic()=delete;
    Dynamic(float cX, float cY, int cWidth, int cHeight, float cSpeed);
    void moveUp(float dt);
    void moveDown(float dt);
    void moveLeft(float dt);
    void moveRight(float dt);
    virtual void draw(std::shared_ptr<sf::RenderWindow> window);
    virtual void update(const float dt);

    void setCustomSpriteData( int timeToNextFrame, int numbersOfFrame, Directory imageDir, int spriteX, int spriteY, int spriteWidth, int spriteHeight);

};


#endif //SFML_GAME_DYNAMIC_H
