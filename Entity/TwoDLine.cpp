//
// Created by Марат Гасанов on 15.04.2022.
//
#include "iostream"
#include "Entity.hpp"

void TwoDLine::render() {
    int direction;
    if (projectionPlane->ordinat->point2->y == 1)
        direction = 1;
    else if (projectionPlane->ordinat->point2->z == 1) direction = 2;
    this->renderable->addLine(this->point1->X, this->point1->Y, this->point2->X, this->point2->Y,
                              projectionPlane->originPoint->x, projectionPlane->originPoint->y, direction, "uzbek");
}

TwoDLine::TwoDLine(const std::shared_ptr<TwoDPoint> &point1, const std::shared_ptr<TwoDPoint> &point2,
                   PTR<ProjectionPlane> plane) {
    this->point1=point1;
    this->point2=point2;
    this->projectionPlane=plane;
}



