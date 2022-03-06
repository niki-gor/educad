#include "line.h"

Line::Line(std::shared_ptr<Point> first, std::shared_ptr<Point> second) : 
    first{ min(first, second) },
    second{ max(first, second) } {}

std::array<float, 3> Line::horizontalCoefficients() const {
    auto&[x1, y1, z1] = first->pos;
    auto&[x2, y2, z2] = second->pos;
    return { y2 - y1, x1 - x2, x2*y1 - x1*y2 };
}

std::array<float, 3> Line::frontalCoefficients() const {
    auto&[x1, y1, z1] = first->pos;
    auto&[x2, y2, z2] = second->pos;
    return { z2 - z1, x1 - x2, x2*z1 - x1*z2 };
}