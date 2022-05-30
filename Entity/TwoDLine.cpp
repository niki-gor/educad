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
                              projectionPlane->originPoint->x, projectionPlane->originPoint->y, direction, "P");
}

TwoDLine::TwoDLine(const std::shared_ptr<TwoDPoint> &point1, const std::shared_ptr<TwoDPoint> &point2,
                   PTR<ProjectionPlane> plane) {
    this->point1=point1;
    this->point2=point2;
    this->projectionPlane=plane;
    A = point1->Y - point2->Y;
    B = point2->X - point1->X;
    C = point1->X*point2->Y - point2->X*point1->Y;
}

void TwoDLine::deleteFromRender() {
    //Гоша сделает
//    renderable->deleteLine()
}

PTR<Entity> TwoDLine::entityByTwoDEntity(PTR<TwoDEntity> secondProjection) {
    return PTR<Entity>();
}

double TwoDLine::getA() const {
    return A;
}

double TwoDLine::getB() const {
    return B;
}

double TwoDLine::getC() const {
    return C;
}

