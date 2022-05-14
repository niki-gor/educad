#ifndef EDUCAD_ANGEMENTITY_H
#define EDUCAD_ANGEMENTITY_H

class AngemEntity {
};

class AngemPoint : AngemEntity {
public:
    AngemPoint(double x, double y, double z) : x(x), y(y), z(z) {};
    AngemPoint() = default;
    double x;
    double y;
    double z;
};

class AngemLine : AngemEntity {
public:
    AngemLine(double i, double j, double k, double x0, double y0, double z0) : i(i), j(j), k(k), x0(x0), y0(y0), z0(z0){};
    AngemLine() = default;
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