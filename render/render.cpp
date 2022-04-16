#include "render.h"

#include <iostream>

void Render::addToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<AngemEntity> object) {
    std::shared_ptr<ProjectionPlane> findedPlane = *planes.find(plane);
    findedPlane->addToProjectionPlane(object);
    observer->onAddToProjectionPlane(object->getTwoDObject(findedPlane));
}

