#pragma once

#include "Entity.hpp"
#include "../AlgoInterface/AlgoInterface.h"
#include "iostream"

class Algo:public AlgoInterface{
public:
    std::vector<std::pair<std::string, std::vector<PTR<Entity>>>> pointOnPlaneProjection(PTR<Point> point, PTR<Plane> plane) override{};
    void doIt();
};