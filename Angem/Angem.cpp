#include "Angem.hpp"

double AngemUtils::getDistance(AngemPoint p1, AngemPoint p2){
    return pow( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2) , 0.5 );
}

AngemLine AngemUtils::getPerpendicularLine(AngemPoint p, AngemLine l){
    double A = l.i;
    double B = l.j;
    double C = l.k;
    double D = l.i * (-p.x) + l.j*(-p.y) + l.k*(-p.z);
    double x1 = (B*l.x0*l.j + C*l.x0*l.k - B*l.i*l.y0 - C*l.i*l.z0 - D*l.i)/(A*A + B*B + C*C);
    double y1 = (A*l.y0*l.i + C*l.y0*l.k - A*l.j*l.x0 - C*l.j*l.z0 - D*l.j)/(A*A + B*B + C*C);
    double z1 = (A*l.z0*l.i + B*l.z0*l.j - A*l.k*l.x0 - B*l.k*l.y0 - D*l.k)/(A*A + B*B + C*C);
    return LineByTwoPoints(PTR<Point>(new PointByCoords(x1,y1,z1)), PTR<Point>(new PointByCoords(p.x, p.y, p.z)));
}



