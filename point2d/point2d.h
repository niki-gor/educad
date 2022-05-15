#pragma once

#include "point2d_base.h"
#include "line2d_base.h"



class Point2DbyCoords : public Point2D {
public:
    virtual bool isInitial() const override final;
    virtual void update() override final;

    Point2DbyCoords(double x, double y) : AngemPoint2D(x, y) {};
};



class Point2DbyLinesIntersection : public Point2D {
private:
    PTR<Line2D> first;
    PTR<Line2D> second;
public:
    virtual bool isInitial() const override final;
    virtual void update() override final;

    Point2DbyLinesIntersection(PTR<Line2D> first, PTR<Line2D> second);
};