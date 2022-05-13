//
// Created by Марат Гасанов on 16.04.2022.
//

#ifndef EDUCAD_ANGEMENTITY_H
#define EDUCAD_ANGEMENTITY_H

class AngemEntity {
};

class AngemPoint : AngemEntity {
public:
    double x;
    double y;
    double z;
};

class AngemLine : AngemEntity {
public:
    // i j k -- направляющий вектор
    double i;
    double j;
    double k;
    double x0;
    double y0;
    double z0;
};

class AngemPlane : AngemEntity {
public:
    double A;
    double B;
    double C;
    double D;
};

#endif //EDUCAD_ANGEMENTITY_H
