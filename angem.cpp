#include "angem.h"

std::array<float, 3> Angem::horizontalCoefficients(Line& line) {
    auto&[x1, y1, z1] = line.first->pos;
    auto&[x2, y2, z2] = line.second->pos;
    return { y2 - y1, x1 - x2, x2*y1 - x1*y2 };
}

std::array<float, 3> Angem::perpendicularHorizontalCoefficients(Line& line, Point& point) {
    auto&[x0, y0, z0] = point.pos;
    auto[a, b, c] = horizontalCoefficients(line);
    return { -b, a, b*x0 - a * y0 };
}

float Angem::det(float& a11, float& a12, float& a21, float& a22) {
    return a11 * a22 - a12 * a21;
}

Point Angem::perpendicularIntersection(Line& line, Point& point) {
    auto[a1, b1, c1] = horizontalCoefficients(line);
    auto[a2, b2, c2] = perpendicularHorizontalCoefficients(line, point);
    return Point(sf::Vector2f(det(b1, c1, b2, c2) / det(a1, b1, a2, b2), det(c1, a1, c2, a2) / det(a1, b1, a2, b2)));
}

std::array<float, 3> Angem::frontalCoefficients(Line& line) {
    auto&[x1, y1, z1] = line.first->pos;
    auto&[x2, y2, z2] = line.second->pos;
    return { z2 - z1, x1 - x2, x2*z1 - x1*z2 };
}

float Angem::distance(Point& first, Point& second) {
    auto&[x1, y1, z1] = first.pos;
    auto&[x2, y2, z2] = second.pos;
    return std::hypot(x1 - x2, y1 - y2);
}

float Angem::distance(Line& line, Point& point) {
    auto[a, b, c] = horizontalCoefficients(line);
    auto&[x0, y0, z0] = point.pos;
    return abs(a*x0 + b*x0 + c) / std::hypot(a, b);
}

float Angem::fastDistance(Point& first, Point& second) {
    auto&[x1, y1, z1] = first.pos;
    auto&[x2, y2, z2] = second.pos;
    return 1 / fastInvSqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

float Angem::fastDistance(Line& line, Point& point) {
    auto[a, b, c] = horizontalCoefficients(line);
    auto&[x0, y0, z0] = point.pos;
    return abs(a*x0 + b*x0 + c)*fastInvSqrt(a*a + b*b);
}

float Angem::scalar(Point& begin, Point& firstEnd, Point& secondEnd) {
    auto&[x0, y0, z0] = begin.pos;
    auto&[x1, y1, z1] = firstEnd.pos;
    auto&[x2, y2, z2] = secondEnd.pos;
    return (x1 - x0)*(x2 - x0) + (y1 - y0)*(y2 - y0);
}

float Angem::fastDistanceToBoundedLine(Line& line, Point& point) {
    if (scalar(*line.first, point, *line.second) < 0 || scalar(*line.second, point, *line.first) < 0)
        return std::min(fastDistance(*line.first, point), fastDistance(*line.second, point));
    return fastDistance(line, point);
}

std::shared_ptr<Point> Angem::nearestPointToPoint(const std::unordered_set<std::shared_ptr<Point>>& points, Point& given) {
    if (points.empty())
        return nullptr;
    return *std::min_element(points.begin(), points.end(), [&given](const auto& lhs, const auto& rhs) {
        return fastDistance(*lhs, given) < fastDistance(*rhs, given);
    });
}

std::shared_ptr<Line> Angem::nearestLineToPoint(const std::unordered_set<std::shared_ptr<Line>, Hash>& lines, Point& given) {
    if (lines.empty())
        return nullptr;
    return *std::min_element(lines.begin(), lines.end(), [&given](const auto& lhs, const auto& rhs) {
        return fastDistanceToBoundedLine(*lhs, given) < fastDistanceToBoundedLine(*rhs, given);
    });
}

float Angem::fastInvSqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - (xhalf*x*x));
    return x;
}