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



class Dynamic
        : public Entity
{
private:
    Status status;
    Directory dir;
    float speed;
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    SpriteData spriteData;
    virtual Status getStatus() const;
    void setStatus(Status status);
    Directory getDirectory() const ;
    void setDir(Directory dir);
public:
    Positions oldPositions;
    Dynamic()=delete;
    Dynamic(float cX, float cY, int cWidth, int cHeight, float cSpeed);
    void moveUp(float dt);
    void moveDown(float dt);
    void moveLeft(float dt);
    void moveRight(float dt);
    virtual void draw(std::shared_ptr<sf::RenderWindow> window);
    virtual void update(const float dt);


};


#endif //SFML_GAME_DYNAMIC_H
