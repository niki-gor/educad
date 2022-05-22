//
// Created by Марат Гасанов on 22.05.2022.
//

#ifndef EDUCAD_RENDERABLEENTITY_H
#define EDUCAD_RENDERABLEENTITY_H
#include "Entity.hpp"
#include "canvas.h"

class RenderableEntity{
    virtual void render() = 0;
};

class RenderablePoint:public RenderableEntity, public TwoDPoint{
    void render(Canvas* canvas);
};

class RenderableLine:public RenderableEntity, public TwoDLine{
    void render(Canvas* canvas);
};

#endif //EDUCAD_RENDERABLEENTITY_H
