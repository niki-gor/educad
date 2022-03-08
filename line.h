#pragma once

#include <memory>
#include <array>
#include "point.h"

class Line {
public:
    const PointPtr first;
    const PointPtr second;
    Line(PointPtr first, PointPtr second);
    bool inFrontalProjection;
    bool inHorizontalProjection;
};

using LinePtr = std::shared_ptr<Line>;