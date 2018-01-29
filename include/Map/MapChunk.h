//
// Created by Streaming on 2018-01-23.
//

#ifndef SFML_GAME_MAPCHUNK_H
#define SFML_GAME_MAPCHUNK_H


#include <Systems/CreatureSpawner.h>

class MapChunk
{
private:
    float playerXonChunk;
    float playerYonChunk;
    std::vector <std::shared_ptr<Entity>> creatureVector;
    std::vector <std::shared_ptr<CreatureSpawner>> creatureSpawner;
    std::vector<std::shared_ptr<Entity>> mapEntity;

public:
    void loadMap();
    void draw(const float dt);
    void update(const float dt);
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);

};


#endif //SFML_GAME_MAPCHUNK_H
