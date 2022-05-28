//
// Created by Марат Гасанов on 28.05.2022.
//

#ifndef EDUCAD_ALGOINTERFACE_H
#define EDUCAD_ALGOINTERFACE_H
#include "Entity.hpp"
#include "render.h"

class AlgoInterface{
    Render* render;
    virtual void pointOnPlaneProjection(PTR<Point> point, PTR<Plane> plane) = 0;
}

#endif //EDUCAD_ALGOINTERFACE_H
