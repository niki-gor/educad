//
// Created by Марат Гасанов on 28.05.2022.
//

#ifndef EDUCAD_ALGOINTERFACE_H
#define EDUCAD_ALGOINTERFACE_H
#include "Entity.hpp"
#include "render.h"
#include "vector"
#include "string"

class AlgoInterface{
public:
    virtual std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> pointOnPlaneProjection(PTR<Point> point, PTR<Plane> plane) = 0;
    virtual algorithm<TwoDEntity> getStraightLevel(PTR<Line> line, PTR<Point> point, PTR<ProjectionPlane> straightPlane) = 0;
};

#endif //EDUCAD_ALGOINTERFACE_H
