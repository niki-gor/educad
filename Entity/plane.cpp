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

ProjectionPlane::ProjectionPlane(PTR<ProjectionPlane> perpendicularProjection, PTR<Line> intersection) { // Не доделал
    A = 1;
    B = 1;
    C = 1;
    D = 1;
    xBegin = 1;
    yBegin = 1;
    zBegin = 1;
}


