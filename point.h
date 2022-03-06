#pragma once

#include <SFML/Graphics.hpp>

class Point {
public:
    enum Shape {
        Triangle = 3, Square, Pentagon, Hexagon
    };
    std::string name;
    sf::Vector3f pos;
    sf::Color color;
    Shape shape;
    bool inFrontalProjection;
    bool inHorizontalProjection;
    Point(Shape shape = Point::Shape(Point::Shape::Triangle + rand() % (Point::Shape::Hexagon - Point::Shape::Triangle + 1)));
    Point(std::string name, sf::Vector3f position, sf::Color color, Shape shape = Shape::Triangle);
};