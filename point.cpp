#include "point.h"

Point::Point(sf::Vector3f pos) : pos{ pos } {}
Point::Point(sf::Vector3f pos, sf::Color color) : pos{ pos }, color{ color } {}