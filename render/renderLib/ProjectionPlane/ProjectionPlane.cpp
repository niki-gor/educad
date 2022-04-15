//
// Created by Марат Гасанов on 14.04.2022.
//

#include "ProjectionPlane.h"
#include "cmath"

ProjectionPlane::ProjectionPlane(double a, double b, double c, double d) {
    koeffs[0] = a;
    koeffs[1] = b;
    koeffs[2] = c;
    koeffs[3] = d;
    double square = a*a + b*b + c*c;
    double t = -d/(square);
    beginCoords[0] = a*t;
    beginCoords[1] = b*t;
    beginCoords[2] = c*t;
}

void ProjectionPlane::addToProjectionPlane(std::shared_ptr<AngemEntity> object) {
    objects.insert(object);
}

void ProjectionPlane::deleteFromProjectionPlane(std::shared_ptr<AngemEntity> object) {
    objects.erase(object);
}

void ProjectionPlane::changeFromProjectionPlane(std::shared_ptr<AngemEntity> oldObject, std::shared_ptr<AngemEntity> newObject) {
    objects.erase(oldObject);
    objects.insert(newObject);
}

