#pragma once

#include "Entity.hpp"
#include "../AlgoInterface/AlgoInterface.h"
#include "iostream"

class Algo:public AlgoInterface{
private:
    AngemPoint getMiddle(AngemPoint p1, AngemPoint p2);
public:
    std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> pointOnPlaneProjection(PTR<Point> point, PTR<Plane> plane) override;
    algorithm<TwoDEntity> getStraightLevel(PTR<Line> line, PTR<Point> point, PTR<ProjectionPlane> straightPlane);
    void doIt();
};