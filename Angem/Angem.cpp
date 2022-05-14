#include "Angem.hpp"
#include <assert.h>
#include "math.h"

double AngemUtils::getDistance(AngemPoint p1, AngemPoint p2){
    return pow( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2) , 0.5 );
}

double AngemUtils::round(double x, int N = 2){
    static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0 };
    double rounded = std::floor(x * powerOfTen[N] + 0.5) / powerOfTen[N];
    return rounded;
}

AngemLine AngemUtils::getPerpendicularLine(AngemPoint p, AngemLine l){
    double A = l.i;
    double B = l.j;
    double C = l.k;
    double D = l.i * (-p.x) + l.j*(-p.y) + l.k*(-p.z);
    double x1 = (B*l.x0*l.j + C*l.x0*l.k - B*l.i*l.y0 - C*l.i*l.z0 - D*l.i)/(A*A + B*B + C*C);
    double y1 = (A*l.y0*l.i + C*l.y0*l.k - A*l.j*l.x0 - C*l.j*l.z0 - D*l.j)/(A*A + B*B + C*C);
    double z1 = (A*l.z0*l.i + B*l.z0*l.j - A*l.k*l.x0 - B*l.k*l.y0 - D*l.k)/(A*A + B*B + C*C);
    return AngemLine(round(p.x) - round(x1), round(p.y) - round(y1), round(p.z) - round(z1), p.x, p.y, p.z);
}

AngemLine AngemUtils::getPerpendicularLine(AngemLine l1, AngemLine l2){
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;
    if(l2.i == l1.i && !l2.i){
        y1 = round((l1.y0 * l2.j * l1.k + l2.j * l2.z0 * l1.j - l1.j * l2.j * l1.z0 - l1.j * l2.k * l2.y0) / (l2.j * l1.k - l1.j * l2.k));
        z1 = round((l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j));
        x1 = 0;
    } else if (l2.j == l1.j && !l2.j){
        x1 = round((l1.x0 * l2.i * l1.k + l2.i * l2.z0 * l1.i - l1.i * l2.i * l1.z0 - l1.i * l2.k * l2.x0) / (l2.i * l1.k - l1.i * l2.k));
        z1 = round((l1.z0 * l2.k * l1.i + l2.k * l2.x0 * l1.k - l1.k * l2.k * l1.x0 - l1.k * l2.i * l2.z0) / (l2.k * l1.i - l1.k * l2.i));
        y1 = 0;
    } else if(l2.k == l1.k && !l2.k){
        x1 = round((l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j));
        y1 = round((l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i));
        z1 = 0;
    } else {
        x1 = round((l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j));
        y1 = round((l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i));
        z1 = round((l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j));
    }
    double i = round(l1.j * l2.k - l1.k * l2.j);
    double j = round(l1.k * l2.i - l1.i * l2.k);
    double k = round(l1.i * l2.j - l1.j * l2.i);
    return AngemLine(i, j, k, x1, y1, z1);
}

AngemLine AngemUtils::getPerpendicularLine(AngemPoint p, AngemPlane s){
    return AngemLine(s.A, s.B, s.C, p.x, p.y, p.z);
}

AngemPoint AngemUtils::linesIntersection(AngemLine l1,AngemLine l2){
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;
    if(l2.i == l1.i && !l2.i){
        y1 = round((l1.y0 * l2.j * l1.k + l2.j * l2.z0 * l1.j - l1.j * l2.j * l1.z0 - l1.j * l2.k * l2.y0) / (l2.j * l1.k - l1.j * l2.k));
        z1 = round((l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j));
        x1 = 0;
    } else if (l2.j == l1.j && !l2.j){
        x1 = round((l1.x0 * l2.i * l1.k + l2.i * l2.z0 * l1.i - l1.i * l2.i * l1.z0 - l1.i * l2.k * l2.x0) / (l2.i * l1.k - l1.i * l2.k));
        z1 = round((l1.z0 * l2.k * l1.i + l2.k * l2.x0 * l1.k - l1.k * l2.k * l1.x0 - l1.k * l2.i * l2.z0) / (l2.k * l1.i - l1.k * l2.i));
        y1 = 0;
    } else if(l2.k == l1.k && !l2.k){
        x1 = round((l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j));
        y1 = round((l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i));
        z1 = 0;
    } else {
        x1 = round((l1.x0 * l2.i * l1.j + l2.i * l2.y0 * l1.i - l1.i * l2.i * l1.y0 - l1.i * l2.j * l2.x0) / (l2.i * l1.j - l1.i * l2.j));
        y1 = round((l1.y0 * l2.j * l1.i + l2.j * l2.x0 * l1.j - l1.j * l2.j * l1.x0 - l1.j * l2.i * l2.y0) / (l2.j * l1.i - l1.j * l2.i));
        z1 = round((l1.z0 * l2.k * l1.j + l2.k * l2.y0 * l1.k - l1.k * l2.k * l1.y0 - l1.k * l2.j * l2.z0) / (l2.k * l1.j - l1.k * l2.j));
    }
    return AngemPoint(x1, y1, z1);
}
AngemLine AngemUtils::planesIntersection(AngemPlane,AngemPlane){
    return AngemLine(0,0,0,0,0,0);
}
AngemLine AngemUtils::parallelLine(AngemLine l, AngemPoint p){
    return AngemLine(l.i, l.j, l.k, p.x, p.y, p.z);
}
AngemPoint AngemUtils::pointOnLine(AngemLine l, double x, double y, double z){
    if(x != NULL){
        
    } else if(y != NULL){
        
    } else {
        
    }
}