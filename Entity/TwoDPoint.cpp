//
// Created by Марат Гасанов on 15.04.2022.
//

#include "TwoDEntity.h"
#include "iostream"
#include "Entity.hpp"


void TwoDPoint::render() {
    std::cout << "Render Point with x: " << X << " y: " << Y << std::endl;
}

TwoDPoint::TwoDPoint(double x, double y, PTR<ProjectionPlane> plane) {
    this->projectionPlane = plane;
}

