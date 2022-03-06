#include "line.h"

Line::Line(std::shared_ptr<Point> first, std::shared_ptr<Point> second) : first{ first }, second{ second } {}