#pragma once

#include "entity2d.h"
#include "angem.h"



// don't confuse: 
// "d" in Eigen::Vector2d stands for double
// "D" in Entity2D stands for Dimension

class Point2D : public Entity2D, public AngemPoint2D {
public:
    virtual std::type_index type() const override final;
    virtual bool isInitial() const override = 0;
    virtual void update() override = 0;
};