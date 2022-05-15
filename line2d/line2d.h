#pragma once

#include "line2d_base.h"
#include "point2d_base.h"
#include "angem.h"



class Line2DbyTwoPoints : public Line2D {
private:
    const PTR<Entity2D> first;
    const PTR<Entity2D> second;
public:
    virtual bool isInitial() const override final;
    virtual void update() override final;

    Line2DbyTwoPoints(PTR<Entity2D> first, PTR<Entity2D> second);
};



class Line2DbyPointAndParallel : public Line2D {
private:
    PTR<Point2D> point;
    PTR<Line2D> parallel;
public:
    virtual bool isInitial() const override final;
    virtual void update() override final;

    Line2DbyPointAndParallel(PTR<Entity2D> point, PTR<Entity2D> parallel);
};