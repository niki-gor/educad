#include "angem.h"

std::array<float, 3> Angem::horizontalCoefficients(Line line) {
    auto[x1, y1, z1] = line.first->pos;
    auto[x2, y2, z2] = line.second->pos;
    return { y2 - y1, x1 - x2, x2*y1 - x1*y2 };
}

std::array<float, 3> Angem::frontalCoefficients(Line line) {
    auto[x1, y1, z1] = line.first->pos;
    auto[x2, y2, z2] = line.second->pos;
    return { z2 - z1, x1 - x2, x2*z1 - x1*z2 };
}

float Angem::distance(Point first, Point second) {
    auto[x1, y1, z1] = first.pos;
    auto[x2, y2, z2] = second.pos;
    return std::hypot(x1 - x2, y1 - y2);
}

float Angem::distance(Line line, Point point) {
    auto[a, b, c] = horizontalCoefficients(line);
    auto[x0, y0, z0] = point.pos;
    return abs(a*x0 + b*x0 + c) / std::hypot(a, b);
}

std::shared_ptr<Point> Angem::nearestPointToPoint(const std::unordered_set<std::shared_ptr<Point>>& points, Point given) {
    if (points.empty())
        return nullptr;
    return *std::min_element(points.begin(), points.end(), [&given](const auto& lhs, const auto& rhs) {
        return distance(*lhs, given) < distance(*rhs, given);
    });
}

std::shared_ptr<Line> Angem::nearestLineToPoint(const std::unordered_set<std::shared_ptr<Line>, Hash>& lines, Point given) {
    if (lines.empty())
        return nullptr;
    return *std::min_element(lines.begin(), lines.end(), [&given](const auto& lhs, const auto& rhs) {
        return distance(*lhs, given) < distance(*rhs, given);
    });
}
