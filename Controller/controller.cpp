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
    disRenderEntity(entity);
}

void Controller::disRenderEntity(PTR<Entity> entity) {
    render->deleteEntity(entity);
}

bool Controller::onCreatePerpendicular(PTR<Entity> point, PTR<Entity> line) {
    if (point->type() == "point" && line->type() == "line"){
        PTR<Point> pointCast = std::dynamic_pointer_cast<Point>(point);
        PTR<Line> lineCast = std::dynamic_pointer_cast<Line>(line);
        PTR<Line> perpendicularLine(new LineByPerpendicular(pointCast, lineCast));
        perpendicularLine->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
        perpendicularLine->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
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
        parallelLine->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
        parallelLine->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
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

bool Controller::onCreatePointOn(double* x, double* y, double* z, PTR<Entity> entity) {
    if (entity->type() == "line"){
        PTR<Line> lineCast = std::dynamic_pointer_cast<Line>(entity);
        PTR<Point> pointOnLine(new PointOnLine(lineCast, x, y, z));
        pointOnLine->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
        pointOnLine->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
        addToModel(pointOnLine);
        renderEntity(pointOnLine);
        return true;
    }

    else if(entity->type() == "plane"){
        PTR<Plane> planeCast = std::dynamic_pointer_cast<Plane>(entity);
        PTR<Point> pointOnPlane(new PointOnPlane(planeCast, x, y, z));
        pointOnPlane->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
        pointOnPlane->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
        addToModel(pointOnPlane);
        renderEntity(pointOnPlane);
        return true;
    }
    return false;
}

bool Controller::onCreatePlaneByThreePoints(PTR<Entity> point1, PTR<Entity> point2, PTR<Entity> point3) {
    if (point1->type() == "point" && point2->type() == "point" && point3->type() == "point"){
        PTR<Point> point1Cast = std::dynamic_pointer_cast<Point>(point1);
        PTR<Point> point2Cast = std::dynamic_pointer_cast<Point>(point2);
        PTR<Point> point3Cast = std::dynamic_pointer_cast<Point>(point3);
        PTR<Plane> planeByThreePoints(new PlaneByThreePoints(point1Cast, point2Cast, point3Cast));
        addToModel(planeByThreePoints);
        renderEntity(planeByThreePoints);
    }
    return false;
}

bool Controller::onCreatePlaneByParallels(PTR<Entity> line1, PTR<Entity> line2) {
    if (line1->type() == "line" && line2->type() == "line"){
        PTR<Line> line1Cast = std::dynamic_pointer_cast<Line>(line1);
        PTR<Line> line2Cast = std::dynamic_pointer_cast<Line>(line2);
        PTR<Plane> plane(new PlaneByParallelLines(line1Cast, line2Cast));
        addToModel(plane);
        renderEntity(plane);
    }
    return false;
}

bool Controller::onCreatePlaneByIntersecting(PTR<Entity> line1, PTR<Entity> line2) {
    if (line1->type() == "line" && line2->type() == "line"){
        PTR<Line> line1Cast = std::dynamic_pointer_cast<Line>(line1);
        PTR<Line> line2Cast = std::dynamic_pointer_cast<Line>(line2);
        PTR<Plane> plane(new PlaneByIntersectingLines(line1Cast, line2Cast));
        addToModel(plane);
        renderEntity(plane);
    }
    return false;
}

bool Controller::onCreatePlaneByLinePoint(PTR<Entity> line, PTR<Entity> point) {
    if (point->type() == "point" && line->type() == "line"){
        PTR<Point> pointCast = std::dynamic_pointer_cast<Point>(point);
        PTR<Line> lineCast = std::dynamic_pointer_cast<Line>(line);
        PTR<Plane> plane(new PlaneByPointAndLine(pointCast, lineCast));
        plane->addProjectionPlane(MAKEPTR<ProjectionPlane> (oxy));
        plane->addProjectionPlane(MAKEPTR<ProjectionPlane> (oxz));
        addToModel(plane);
        renderEntity(plane);
    }
    return false;
}

bool Controller::onAddPointOnPlaneProjectionAlgo(PTR<Entity> plane, PTR<Entity> point) {
    if (plane->type() == "plane" && point->type() == "point"){
        PTR<Plane> plane = std::dynamic_pointer_cast<Plane>(plane);
        PTR<Point> point = std::dynamic_pointer_cast<Point>(point);
        if (AngemUtils::isPointOnPlane(*plane, *point)){
            algo->pointOnPlaneProjection(point, plane);
        }
    }
    return false;
}

PTR<Entity> Controller::onLinkToPlane(double *x, double *y, double *z, PTR<Entity> plane) {
    if (plane->type() == "plane"){
        PTR<Plane> planeCast = std::dynamic_pointer_cast<Plane>(plane);
        PTR<Point> point(new PointOnPlane(planeCast, x, y, z));
//        point->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxy));
//        point->addProjectionPlane(MAKEPTR<ProjectionPlane>(oxz));
        return point;
    }
    return nullptr;
}
