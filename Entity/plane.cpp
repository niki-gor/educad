//
// Created by Марат Гасанов on 17.04.2022.
//

#include "Entity.hpp"

PlaneByThreePoints::PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3) { // Не доделал
    first = p1;
    second = p2;
    third = p3;
    A = 1;
    B  = 1;
    C = 1;
    D = 1;
}

ProjectionPlane::ProjectionPlane(const PTR<Plane>& plane) {
    PTR<Point> zeroPoint(new PointByCoords(0, 0, 0));
    originPoint = zeroPoint->getProjectionOnPlane(plane);
    PTR<Line> abscis(new LineByPlanesIntersection(PTR<Plane>(this), plane));
    AngemLine line = AngemUtils::getPerpendicularLine(*originPoint, *abscis);
    PTR<Line> ordinat(new LineByParametres(line.i, line.j, line.k, originPoint->x, originPoint->y, originPoint->z));
    this->ordinat = ordinat;
    this->absciss = abscis;
}

ProjectionPlane::ProjectionPlane(double A, double B, double C, double D) {
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    PTR<Point> p1(new PointByCoords(0, 0, 0));
    PTR<Point> p2(new PointByCoords(1, 0, 0));
    PTR<Point> p3(new PointByCoords(0,1,0));
    PTR<Line> abscis(new LineByTwoPoints(p1, p2));
    if (C){
        PTR<Line> ord(new LineByTwoPoints(p1, p2));
        ordinat = ord;
    }
    else{
        PTR<Line> ord(new LineByTwoPoints(p1, p3));
        ordinat = ord;
    }
    originPoint = PTR<Point>(new PointByCoords(0, 0, 0));
    absciss = abscis;
}


