//
// Created by Марат Гасанов on 16.04.2022.
//

#ifndef PROJECTNAME_TWODENTITY_H
#define PROJECTNAME_TWODENTITY_H
#include "memory"

class TwoDEntity{
    virtual void render() = 0;
};

class TwoDPoint : TwoDEntity{
public:
    double x;
    double y;
    TwoDPoint(double x, double y): x(x), y(y){};
    void render();
};

class TwoDLine : TwoDEntity{
private:
    double a;
    double b;
    double c;
    std::shared_ptr<TwoDPoint> point1;
    std::shared_ptr<TwoDPoint> point2;
public:
    TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2);
    TwoDLine(double a, double b, double c) : a(a), b(b), c(c){};
    void render();
};



#endif //PROJECTNAME_TWODENTITY_H
