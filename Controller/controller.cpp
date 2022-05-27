//
// Created by Марат Гасанов on 14.05.2022.
//

#include "controller.h"

Controller::Controller(Render* render): render(render), oxy(ProjectionPlane(0, 0, 1, 0)), oxz(ProjectionPlane(0, 1, 0, 0)){
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

bool Controller::onCreatePerpendicular(PTR<Entity> point, PTR<Entity> line) {
    if (point->type() == "point" && line->type() == "line"){
        PTR<Point> pointCast = std::dynamic_pointer_cast<Point>(point);
        PTR<Line> lineCast = std::dynamic_pointer_cast<Line>(line);
        PTR<Line> perpendicularLine(new LineByPerpendicular(pointCast, lineCast));
        addToModel(perpendicularLine);
        renderEntity(perpendicularLine);
        return true;
    }
    return false;
}

bool Controller::onCreateParallelLine(PTR<Entity> line, PTR<Entity> point) {
    if (line->type() == "line" && point->type() == "point"){
        PTR<Line> lineCast = std::dynamic_pointer_cast<Line>(line);
        PTR<Point> pointCast = std::dynamic_pointer_cast<Point>(point);
        PTR<Line> parallelLine(new LineByParallel(pointCast, lineCast));
        addToModel(parallelLine);
        renderEntity(parallelLine);
    }
}

bool Controller::onCreateLineByTwoPoint(PTR<Entity> point1, PTR<Entity> point2) {
    if (point1->type() == "point" && point2->type() == "point"){
        PTR<Point> point1Cast = std::dynamic_pointer_cast<Point>(point1);
        PTR<Point> point2Cast = std::dynamic_pointer_cast<Point>(point2);
        PTR<Line> lineByTwoPoints(new LineByTwoPoints(point1Cast, point2Cast));
        lineByTwoPoints->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
        lineByTwoPoints->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
        addToModel(lineByTwoPoints);
        renderEntity(lineByTwoPoints);
        return true;
    }
    return false;
}
