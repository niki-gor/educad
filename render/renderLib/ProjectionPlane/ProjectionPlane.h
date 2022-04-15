//
// Created by Марат Гасанов on 14.04.2022.
//

#ifndef RENDER_PROJECTIONPLANE_H
#define RENDER_PROJECTIONPLANE_H

#include <set>
#include "../TwoDObject/TwoDObject.h"
#include "../AngemEntity/AngemEntity.h"

class ProjectionPlane{
private:
    double koeffs[4];
    std::set<std::shared_ptr<AngemEntity>> objects;
    double beginCoords[3];
public:
    ProjectionPlane(double x, double y, double z, double d);
    void addToProjectionPlane(std::shared_ptr<AngemEntity> object);
    void deleteFromProjectionPlane(std::shared_ptr<AngemEntity> object);
    void changeFromProjectionPlane(std::shared_ptr<AngemEntity> oldObject, std::shared_ptr<AngemEntity> newObject);
};

#endif //RENDER_PROJECTIONPLANE_H
