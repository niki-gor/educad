#pragma once

#include <SFML/Graphics.hpp>

class Point {
public:
    std::string name;
    sf::Vector3f pos;
    sf::Color color;
    bool inFrontalProjection;
    bool inHorizontalProjection;
    Point();
    Point(std::string name, sf::Vector3f position, sf::Color color);
};