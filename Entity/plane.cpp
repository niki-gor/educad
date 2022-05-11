#include "Entity.hpp"

PlaneByThreePoints::PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3) { // Не доделал
    first = p1;
    second = p2;
    third = p3;
    //line 1
    double i1 = p2->x - p1->x;
    double j1 = p2->y - p1->y;
    double k1 = p2->z - p1->z;
    //line 2
    double i2 = p3->x - p1->x;
    double j2 = p3->y - p1->y;
    double k2 = p3->z - p1->z;
    /*
    i   j   k
    i1  j1  k1
    i2  j2  k2
    */
    A = j1*k2 - k1*j2;
    B = k1*i2 - i1*k2;
    C = i1*j2 - j1*i2;
    D = A*(-p1->x) + B*(-p1->y) + C*(-p1->z);
}

PlaneByPointAndLine::PlaneByPointAndLine(PTR<Point> p, PTR<Line> l){
    point = p;
    line = l;

    //line 1
    double i1 = l->x0 - p->x;
    double j1 = l->y0 - p->y;
    double k1 = l->z0 - p->z;

    //[line 1 x l]
    A = j1*l->k - k1*l->j;
    B = k1*l->i - i1*l->k;
    C = i1*l->j - j1*l->i;
    D = A*(-p->x) + B*(-p->y) + C*(-p->z);
}

PlaneByIntersectingLines::PlaneByIntersectingLines(PTR<Line> l, PTR<Line> l1){
    first = l;
    second = l1;

    //[line 1 x l]
    A = l1->j*l->k - l1->k*l->j;
    B = l1->k*l->i - l1->i*l->k;
    C = l1->i*l->j - l1->j*l->i;
    D = A*(-l->x0) + B*(-l->y0) + C*(-l->z0);
}

PlaneByParallelLines::PlaneByParallelLines(PTR<Line> l, PTR<Line> l1){
    first = l;
    second = l1;
    
    //intersected line
    double i1 = l->x0 - l1->x0;
    double j1 = l->y0 - l1->y0;
    double k1 = l->z0 - l1->z0;
    
    A = j1*l->k - k1*l->j;
    B = k1*l->i - i1*l->k;
    C = i1*l->j - j1*l->i;
    D = A*(-l->x0) + B*(-l->y0) + C*(-l->z0);
}

ProjectionPlane::ProjectionPlane(PTR<ProjectionPlane> perpendicularProjection, PTR<Line> intersection) { // Не доделал
    A = 1;
    B = 1;
    C = 1;
    D = 1;
    xBegin = 1;
    yBegin = 1;
    zBegin = 1;
}

ProjectionPlane::ProjectionPlane(PTR<Plane> plane) {
    A = plane->A;
    B = plane->B;
    C = plane->C;
    D = plane->D;
    xBegin = 1;
    yBegin = 1;
    zBegin = 1;
}



