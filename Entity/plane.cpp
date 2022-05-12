//
// Created by Марат Гасанов on 17.04.2022.
//

#include "Entity.hpp"

PlaneByThreePoints::PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3) { // Не доделал
    first = p1;
    second = p2;
    third = p3;
    A = 1;
    B  = 1;
    C = 1;
    D = 1;
}

ProjectionPlane::ProjectionPlane(const PTR<Plane>& perpendicularPlane, PTR<Line> intersection) { // Не доделал
    A = perpendicularPlane->A;
    B = perpendicularPlane->B;
    C = perpendicularPlane->C;
    D = perpendicularPlane->D;
    double square = A*A + B*B + C*C;
    double t = -D/(square);
    xBegin = A*t;
    yBegin = B*t;
    zBegin = C*t;
}

ProjectionPlane::ProjectionPlane(PTR<Plane> plane) {
    A = plane->A;
    B = plane->B;
    C = plane->C;
    D = plane->D;
    xBegin = 1;
    yBegin = 1;
    zBegin = 1;
}


