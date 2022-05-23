//
// Created by Марат Гасанов on 14.05.2022.
//

#include "controller.h"

Controller::Controller(Render* render): render(render), oxy(ProjectionPlane(0, 0, 1, 0)), oxz(ProjectionPlane(1, 0, 0, 0)){
}

void Controller::addToModel(PTR<Entity> entity) {
//    lineWorker->AddToModel(entity);
}


void Controller::renderEntity(PTR<Entity> entity) {
    render->addEntity(entity);
}

void Controller::onAddEntity(PTR<Entity> entity) {
    entity->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
    entity->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
    addToModel(entity);
    //renderEntity(entity);
}

void Controller::onDeleteEntity(PTR<Entity> entity) {
//    lineWorker->DeleteEntity(entity);
//    disRenderEntity(entity);
}

void Controller::disRenderEntity(PTR<Entity> entity) {
    render->deleteEntity(entity);
}

void Controller::onCreatePerpendicular(PTR<Point> point, PTR<Line> line) {
    PTR<Line> perpendicularLine(new LineByPerpendicular(point, line));
    addToModel(perpendicularLine);
    renderEntity(perpendicularLine);
}

void Controller::onCreateParallelLine(PTR<Line> line, PTR<Point> point) {
    PTR<Line> parallelLine(new LineByParallel(point, line));
    addToModel(parallelLine);
    renderEntity(parallelLine);
}

void Controller::onCreateLineByTwoPoint(PTR<Point> point1, PTR<Point> point2) {
    PTR<Line> lineByTwoPoints(new LineByTwoPoints(point1, point2));
    addToModel(lineByTwoPoints);
    renderEntity(lineByTwoPoints);
}
