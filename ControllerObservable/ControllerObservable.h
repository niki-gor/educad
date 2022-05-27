//
// Created by Марат Гасанов on 13.05.2022.
//

#ifndef EDUCAD_CONTROLLEROBSERVABLE_H
#define EDUCAD_CONTROLLEROBSERVABLE_H
#include "Entity.hpp"

class ControllerObservable{
public:
    virtual void onAddEntity(PTR<Entity> entity) = 0;
    virtual void onDeleteEntity(PTR<Entity> entity) = 0;
    virtual bool onCreatePerpendicular(PTR<Entity> point, PTR<Entity> line) = 0;
    virtual bool onCreateParallelLine(PTR<Entity> line, PTR<Entity> point) = 0;
    virtual bool onCreateLineByTwoPoint(PTR<Entity> point1, PTR<Entity> point2) = 0;
    virtual bool onCreatePointOn(double* x, double* y, double* z, PTR<Entity> entity) = 0;
};

#endif //EDUCAD_CONTROLLEROBSERVABLE_H
