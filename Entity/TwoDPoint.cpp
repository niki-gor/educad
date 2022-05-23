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
    // George`s code
    this->renderable->addPoint();
}
