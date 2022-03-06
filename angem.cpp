#include "angem.h"

/*
float Angem::distance(Point first, Point second) {
    auto&[x1, y1, z1] = first.pos;
    auto&[x2, y2, z2] = second.pos;
    return std::hypot(x2 - x1, y2 - y1);
}*/

float Angem::distance(float x1, float y1, float x2, float y2) {
    return std::hypot(x1 - x2, y1 - y2);
};

std::shared_ptr<Point> Angem::nearestPointToPoint(const std::unordered_set<std::shared_ptr<Point>>& points, Point given) {
    if (points.empty())
        return nullptr;
    return *std::min_element(points.begin(), points.end(), [&given](const auto& lhs, const auto& rhs) {
        return distance(lhs->pos.x, lhs->pos.y, given.pos.x, given.pos.y) < distance(rhs->pos.x, rhs->pos.y, given.pos.x, given.pos.y);
    });
}
