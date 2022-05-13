//
// Created by Марат Гасанов on 14.05.2022.
//

#include "controller.h"

Controller::Controller(): oxy(ProjectionPlane(0, 0, 1, 0)), oxz(ProjectionPlane(1, 0, 0, 0)){
    render = Render();
}

void Controller::addToModel(PTR<Entity> entity) {
    lineWorker->AddToModel(entity);
}


void Controller::renderEntity(PTR<Entity> entity) {
    render.addEntity(entity);
}

void Controller::onAddEntity(PTR<Entity> entity) {
    entity->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
    entity->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
    addToModel(entity);
    renderEntity(entity);
}

void Controller::onDeleteEntity(PTR<Entity> entity) {
    lineWorker->DeleteEntity(entity);
    disRenderEntity(entity);
}

void Controller::disRenderEntity(PTR<Entity> entity) {
    render.deleteEntity(entity);
}
