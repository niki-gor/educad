#include "render.h"

#include <iostream>

void Render::addToProjectionPlane(const std::shared_ptr<ProjectionPlane>& plane, const std::shared_ptr<Entity>& object) {
    if (planes.find(plane) == planes.end()) {
        planes.insert(plane);
    }

    plane->add(object);
    object->addProjectionPlane(plane);
    observer->onAddToProjectionPlane(plane, object->getProjection(plane));
}

void Render::deleteFromPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object) {
    std::shared_ptr<ProjectionPlane> findedPlane = *planes.find(plane);
    planes.erase(findedPlane);
    object->deleteProjectionPlane(findedPlane);
}

void Render::changeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object) {
    observer->onChangeFromProjectionPlane(plane, object->getProjection(plane));
}

