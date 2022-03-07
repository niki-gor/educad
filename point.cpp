#include "point.h"

Point::Point(Vec3 pos) : pos{ pos } {}
Point::Point(Vec3 pos, sf::Color color) : pos{ pos }, color{ color } {}