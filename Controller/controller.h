//
// Created by Марат Гасанов on 13.05.2022.
//

#ifndef EDUCAD_CONTROLLER_H
#define EDUCAD_CONTROLLER_H
#include "render.h"
#include "AngemModelWorker.h"
#include "ControllerObservable.h"
#include "TwoDEntity.h"

class Controller:ControllerObservable{
private:
    AngemModelWorker* lineWorker;
    AngemModelWorker* pointWorker;
    void addToModel(PTR<Entity> entity);
    void renderEntity(PTR<Entity> entity);
    void disRenderEntity(PTR<Entity> entity);
    Render render;
    ProjectionPlane oxy;
    ProjectionPlane oxz;
public:
    Controller();
    void onAddEntity(PTR<Entity> entity) override;
    void onDeleteEntity(PTR<Entity> entity) override;
};

#endif //EDUCAD_CONTROLLER_H
