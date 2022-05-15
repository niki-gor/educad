#include "point2d.h"



std::type_index Point2D::type() const {
    return typeid(Point2D);
}

Point2DbyCoords::Point2DbyCoords(double x, double y) {}