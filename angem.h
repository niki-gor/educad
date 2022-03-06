#pragma once

#include <unordered_set>
#include "point.h"
#include "line.h"

class Angem {
public:
    static float distance(float, float, float, float);
    static std::shared_ptr<Point> nearestPointToPoint(const std::unordered_set<std::shared_ptr<Point>>&, Point);
};