#include "entity2d.h"



Entity2D::~Entity2D() {}

void Entity2D::update() {
    for (auto& i : children) {
        i->update();
    }
}

Polyset<Entity2D> operator+(PTR<Entity2D> left, PTR<Entity2D> right) {
    Polyset<Entity2D> result;
    result.insert(left);
    result.insert(right);
    return result;
}

Polyset<Entity2D> operator+(Polyset<Entity2D> left, PTR<Entity2D> right) {
    left.insert(right);
    return left;
}