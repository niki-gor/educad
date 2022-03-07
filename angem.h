#pragma once

#include <unordered_set>
#include "point.h"
#include "line.h"
#include "hash.h"

class Angem {
public:
    static std::array<float, 3> horizontalCoefficients(Line&);
    static std::array<float, 3> perpendicularHorizontalCoefficients(Line&, Point&);
    static std::array<float, 3> frontalCoefficients(Line&);
    static Point perpendicularIntersection(Line&, Point&);
    static float det(float&, float&, float&, float&);
    static float distance(Point&, Point&);
    static float distance(Line&, Point&);
    static float fastDistance(Point&, Point&);
    static float fastDistance(Line&, Point&);
    static float fastDistanceToBoundedLine(Line&, Point&);
    static float scalar(Point&, Point&, Point&);
    static std::shared_ptr<Point> nearestPointToPoint(const std::unordered_set<std::shared_ptr<Point>>&, Point&);
    static std::shared_ptr<Line> nearestLineToPoint(const std::unordered_set<std::shared_ptr<Line>, Hash>&, Point&);
    static float fastInvSqrt(float);
};