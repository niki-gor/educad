//
// Created by Марат Гасанов on 13.05.2022.
//

#ifndef EDUCAD_CONTROLLER_H
#define EDUCAD_CONTROLLER_H
#include "render.h"
#include "AngemModelWorker.hpp"
#include "../ControllerObservable/ControllerObservable.h"
#include "Angem.hpp"

class Controller: public ControllerObservable{
private:
//    AngemModelWorker* worker;
    void addToModel(PTR<Entity> entity);
    void renderEntity(PTR<Entity> entity);
    void disRenderEntity(PTR<Entity> entity);
    Render* render;
    ProjectionPlane oxy;
    ProjectionPlane oxz;
public:
    bool onCreateLineByTwoPoint(PTR<Entity> point1, PTR<Entity> point2) override;

    bool onCreatePerpendicular(PTR<Entity> point, PTR<Entity> line) override;

    bool onCreateParallelLine(PTR<Entity> line, PTR<Entity> point) override;

    explicit Controller(Render* render);
    void onAddEntity(PTR<Entity> entity) override;
    void onDeleteEntity(PTR<Entity> entity) override;

    bool onCreatePointOn(double* x, double * y, double * z, PTR<Entity> line) override;
};

#endif //EDUCAD_CONTROLLER_H
