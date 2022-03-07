#pragma once

#include <SFML/Graphics.hpp>
#include "vec3.h"


class Point {
public:
    Vec3 pos;
    std::string name;
    sf::Color color;
    bool inFrontalProjection;
    bool inHorizontalProjection;

    Point(Vec3 pos);
    Point(Vec3 pos, sf::Color color);
};