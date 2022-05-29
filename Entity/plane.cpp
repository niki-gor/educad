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
//    p1->addChildren(PTR<Entity>(this));
//    p2->addChildren(PTR<Entity>(this));
//    p3->addChildren(PTR<Entity>(this));
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
//    p->addChildren(PTR<Entity>(this));
//    l->addChildren(PTR<Entity>(this));
}

PlaneByIntersectingLines::PlaneByIntersectingLines(PTR<Line> l, PTR<Line> l1){
    first = l;
    second = l1;

    //[line 1 x l]
    A = l1->j*l->k - l1->k*l->j;
    B = l1->k*l->i - l1->i*l->k;
    C = l1->i*l->j - l1->j*l->i;
    D = A*(-l->x0) + B*(-l->y0) + C*(-l->z0);
    AngemPoint interSecting = AngemUtils::linesIntersection(*l, *l1);
//    l->addChildren(PTR<Entity>(this));
//    l1->addChildren(PTR<Entity>(this));
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

std::vector<PTR<Entity> > PlaneByThreePoints::getParents() const{
    return {first, second, third};
}

std::vector<PTR<Entity> > PlaneByPointAndLine::getParents() const{
    return {point, line};
}

std::vector<PTR<Entity> > PlaneByIntersectingLines::getParents() const{
    return {first, second};
}

std::vector<PTR<Entity> > PlaneByParallelLines::getParents() const{
    return {first, second};
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
    PTR<Point> p4(new PointByCoords(0,0,1));
    PTR<Line> abscis(new LineByTwoPoints(p1, p2));
    if (C){
        PTR<Line> ord(new LineByTwoPoints(p1, p3));
        ordinat = ord;
    }
    else{
        PTR<Line> ord(new LineByTwoPoints(p1, p4));
        ordinat = ord;
    }
    originPoint = PTR<Point>(new PointByCoords(0, 0, 0));
    absciss = abscis;
}




