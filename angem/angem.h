#pragma once

#include <array>



struct Position2D {
    double x;
    double y;
    Position2D(double x, double y) : x{x}, y{y} {};
};

struct Position3D {
    double x;
    double y;
    double z;
    Position3D(double x, double y, double z) : x{x}, y{y}, z{z} {};
};

struct LineEquation2D {
    double A;
    double B;
    double C;
    LineEquation2D(double A, double B, double C) : A{A}, B{B}, C{C} {}
};

struct PlaneEquation3D {
    double A;
    double B;
    double C;
    double D;
};

struct CirclePosition2D {
    double x;
    double y;
    double r;
};

struct SpherePosition3D {
    double x;
    double y;
    double z;
    double r;
};


class AngemPoint2D {
private:
    Position2D position;
public:
    Position2D getPosition() const;
    AngemPoint2D(double x, double y) : position(x, y) {}
};



class AngemLine2D {
private:
    LineEquation2D equation;
public:
    LineEquation2D getEquation() const;
    AngemLine2D(double A, double B, double C) : equation(A, B, C) {}
};



class AngemPlane3D {
private:
    PlaneEquation3D equation;
public:
    PlaneEquation3D getEquation() const;
};



class AngemCircle2D {
private:
    CirclePosition2D position;
public:
    CirclePosition2D getPosition() const;
};



class AngemSphere3D {
private:
    SpherePosition3D position;
public:
    SpherePosition3D getPosition() const;
};