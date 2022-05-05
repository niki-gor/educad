#include "vec3.h"

Vec3::Vec3() {}
Vec3::Vec3(Vec2 vec2) : x{ vec2.x }, y{ vec2.y }, z{ 0 }{}
Vec3::Vec3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}
Vec3::operator Vec2() const {
    return Vec2(x, y);
}