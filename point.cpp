#include "point.h"

Point::Point() {}

Point::Point(std::string name, sf::Vector3f pos, sf::Color color) : 
    name{ name }, pos{ pos }, color{ color } {}