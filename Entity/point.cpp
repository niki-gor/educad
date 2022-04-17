//
// Created by Марат Гасанов on 16.04.2022.
//

#include "Entity.hpp"

PointByCoords::PointByCoords(double x, double y, double z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

PointByLinesIntersection::PointByLinesIntersection(PTR<Line> first, PTR<Line> second) {//не доделал
    x = 1;
    y = 1;
    z = 1;
}
