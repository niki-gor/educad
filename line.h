#pragma once

#include <memory>
#include <array>
#include "point.h"

class Line {
public:
    const std::shared_ptr<Point> first;
    const std::shared_ptr<Point> second;
    Line(std::shared_ptr<Point> first, std::shared_ptr<Point> second);
    bool inFrontalProjection;
    bool inHorizontalProjection;
    std::array<float, 3> horizontalCoefficients() const;
    std::array<float, 3> frontalCoefficients() const;
};