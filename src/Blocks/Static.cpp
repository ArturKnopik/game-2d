//
// Created by Root on 13.01.2018.
//

#include "Blocks/Static.h"

Static::Static(float cX, float cY, int cWidth, int cHeight)
        : Entity(cX, cY, cWidth, cHeight) {
    setTypeOfEntity(GROUND);
    setCollisionStatus(NO_COLLISION);
}

SpriteData Static::getSpriteData() {
    return spriteData;
}

void Static::setSpriteData(SpriteData spriteData) {
    this->spriteData = spriteData;
}

