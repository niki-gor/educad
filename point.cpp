#include "point.h"

Point::Point(sf::Vector2f pos) : pos{ pos.x, pos.y, 0 } {}
Point::Point(sf::Vector2f pos, sf::Color color) : pos{ pos.x, pos.y, 0 }, color{ color } {}
Point::Point(sf::Vector3f pos) : pos{ pos } {}
Point::Point(sf::Vector3f pos, sf::Color color) : pos{ pos }, color{ color } {}