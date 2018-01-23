//
// Created by Root on 13.01.2018.
//

#include "Blocks/Static.h"

Static::Static(float cX, float cY, int cWidth, int cHeight)
:Entity(cX, cY, cWidth, cHeight)
{
    setCollisionStatus(CAN_NOT_BE_COLLIDET);
}
