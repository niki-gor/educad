#pragma once

#include "entity2d.h"
#include "angem.h"



class Line2D : public Entity2D, public AngemLine2D {
public:
    virtual std::type_index type() const override final;
    virtual bool isInitial() const override = 0;
    virtual void update() override = 0;
};

