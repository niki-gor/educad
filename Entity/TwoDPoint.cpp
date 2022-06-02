//
// Created by Марат Гасанов on 15.04.2022.
//

#include "iostream"
#include "Entity.hpp"

TwoDPoint::TwoDPoint(double x, double y, PTR<ProjectionPlane> plane) {
    this->projectionPlane = plane;
    this->X = x;
    this->Y = y;
}

void TwoDPoint::render() {
    int direction;
    if (projectionPlane->ordinat->point2->y == 1) {
        direction = 1;
    }
    else if (projectionPlane->ordinat->point2->z == 1) direction = 2;
    this->renderable->addPoint(X, Y, projectionPlane->originPoint->x, projectionPlane->originPoint->y, direction, "L",
                               this);
}

void TwoDPoint::deleteFromRender() {
    //гоша сделает
//renderable->addPoint()
}

PTR<Entity> TwoDPoint::entityByTwoDEntity(PTR<TwoDEntity> secondProjection) {
//    return PTR<Entity>(new PointByCoords(this->X, ));
}



