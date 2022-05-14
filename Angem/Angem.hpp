#ifndef ANGEM_HPP
#define ANGEM_HPP

#include <memory>
#include "utils.h"
#include "AngemEntity.h"


namespace AngemUtils {
    double getDistance(AngemPoint p1, AngemPoint p2);
    AngemLine getPerpendicularLine(AngemPoint p, AngemLine l);

    AngemLine getPerpendicularLine(AngemLine l1, AngemLine l2);

    AngemLine getPerpendicularLine(AngemPoint p, AngemPlane s);
    AngemPoint linesIntersection(AngemLine l1,AngemLine l2);
    AngemLine planesIntersection(AngemPlane,AngemPlane);
    AngemLine parallelLine(AngemLine, AngemPoint);
    double round(double x, int N=2);
    AngemPoint pointOnLine(AngemLine l, double x, double y, double z);
};

#endif