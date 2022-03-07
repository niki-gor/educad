#pragma once

#include "vec2.h"
#include <tuple>

class Vec3 {
public:
    float x;
    float y;
    float z;
    Vec3();
    Vec3(Vec2);
    Vec3(float x, float y, float z);
    operator Vec2() const;
};
