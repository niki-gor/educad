//
// Created by Марат Гасанов on 13.05.2022.
//

#ifndef EDUCAD_CONTROLLEROBSERVABLE_H
#define EDUCAD_CONTROLLEROBSERVABLE_H
#include "TwoDEntity.h"
#include "Entity.hpp"

class ControllerObservable{
public:
    virtual void onAddEntity(PTR<Entity> entity) = 0;
    virtual void onDeleteEntity(PTR<Entity> entity) = 0;
    virtual void onCreatePerpendicular(PTR<Point> point, PTR<Line> line) = 0;
    virtual void onCreateParallelLine(PTR<Line> line, PTR<Point> point) = 0;
    virtual void onCreateLineByTwoPoint(PTR<Point> point1, PTR<Point> point2) = 0;
};

#endif //EDUCAD_CONTROLLEROBSERVABLE_H
