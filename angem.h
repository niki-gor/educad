#pragma once

#include <unordered_set>
#include "point.h"
#include "line.h"
#include "hash.h"

class Angem {
public:
    static std::array<float, 3> horizontalCoefficients(Line);
    static std::array<float, 3> frontalCoefficients(Line);
    static float distance(Point, Point);
    static float distance(Line, Point);
    static std::shared_ptr<Point> nearestPointToPoint(const std::unordered_set<std::shared_ptr<Point>>&, Point);
    static std::shared_ptr<Line> nearestLineToPoint(const std::unordered_set<std::shared_ptr<Line>, Hash>&, Point);
};