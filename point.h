#pragma once

#include <SFML/Graphics.hpp>


class Point {
public:
    std::string name;
    sf::Vector3f pos;
    sf::Color color;
    bool inFrontalProjection;
    bool inHorizontalProjection;

    Point(sf::Vector2f);
    Point(sf::Vector2f pos, sf::Color color);
    Point(sf::Vector3f);
    Point(sf::Vector3f, sf::Color);
};