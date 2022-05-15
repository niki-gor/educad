#pragma once

#include <unordered_set>
#include "utils.h"
#include "polyset.h"



class Entity2D {
private:
    std::unordered_set<PTR<Entity2D>> children;
public:
    virtual ~Entity2D();

    virtual std::type_index type() const = 0;
    virtual bool isInitial() const = 0;
    virtual void update();
};

Polyset<Entity2D> operator+(PTR<Entity2D> left, PTR<Entity2D> right);
Polyset<Entity2D> operator+(Polyset<Entity2D> left, PTR<Entity2D> right);