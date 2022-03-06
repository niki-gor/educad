#include "line.h"

Line::Line(std::shared_ptr<Point> first, std::shared_ptr<Point> second) : 
    first{ min(first, second) },
    second{ max(first, second) } {}