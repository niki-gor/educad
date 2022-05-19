//
// Created by Марат Гасанов on 16.04.2022.
//

#ifndef PROJECTNAME_TWODENTITY_H
#define PROJECTNAME_TWODENTITY_H
#include "memory"

class TwoDEntity{
public:
    virtual void render() = 0;
};

class TwoDPoint : public TwoDEntity{
public:
    double X;
    double Y;
    TwoDPoint(double x, double y): X(x), Y(y){};
    void render();
};

class TwoDLine : public TwoDEntity{
private:
    double A;
    double B;
    double C;
public:
    std::shared_ptr<TwoDPoint> point1;
    std::shared_ptr<TwoDPoint> point2;
    TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2);
    void render();
};


#endif //PROJECTNAME_TWODENTITY_H
