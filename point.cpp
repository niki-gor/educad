#include "point.h"

Point::Point(Shape shape) : shape{ shape } {}

Point::Point(std::string name, sf::Vector3f pos, sf::Color color, Shape shape) : 
    name{ name }, pos{ pos }, color{ color }, shape{ shape } {}