#pragma once

#include <memory>
#include "Utils.hpp"
#include "AngemEntity.h"


namespace AngemUtils {
    double getDistance(AngemPoint p1, AngemPoint p2);

    AngemLine getPerpendicularLine(AngemPoint p, AngemLine l){
        return AngemLine();
    }
    AngemLine getPerpendicularLine(AngemLine l1, AngemLine l2){
        return AngemLine();
    }
    AngemLine getPerpendicularLine(AngemPoint p, AngemPlane s){
        return AngemLine();
    }
    AngemPoint linesIntersection(AngemLine l1,AngemLine l2){
        return AngemPoint();
    }
    AngemLine planesIntersection(AngemPlane,AngemPlane){
        return AngemLine();
    }
    AngemLine parallelLine(AngemLine, AngemPoint){
        return AngemLine();
    }
};




