//
// Created by Марат Гасанов on 15.04.2022.
//

#ifndef RENDER_TWODPOINT_H
#define RENDER_TWODPOINT_H
#include "TwoDObject.h"

class TwoDPoint : TwoDObject{
public:
    double x;
    double y;
    TwoDPoint(double x, double y): x(x), y(y){};
    void render() override;
};

#endif //RENDER_TWODPOINT_H
