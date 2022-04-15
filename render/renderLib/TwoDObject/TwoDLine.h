//
// Created by Марат Гасанов on 15.04.2022.
//

#ifndef RENDER_TWODLINE_H
#define RENDER_TWODLINE_H

#include <memory>
#include "TwoDObject.h"
#include "TwoDPoint.h"

class TwoDLine : TwoDObject{
private:
    double a;
    double b;
    double c;
    std::shared_ptr<TwoDPoint> point1;
    std::shared_ptr<TwoDPoint> point2;
public:
    TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2);
    TwoDLine(double a, double b, double c) : a(a), b(b), c(c){};
    void render() override;
};

#endif //RENDER_TWODLINE_H
