#include "line.h"

Line::Line(PointPtr first, PointPtr second) : 
    first{ min(first, second) },
    second{ max(first, second) } {}