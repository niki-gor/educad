#include "render.h"

#include <iostream>

void Render::addToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object) {
    std::shared_ptr<ProjectionPlane> findedPlane = *planes.find(plane);
    findedPlane->add(object);
    object->addProjectionPlane(plane);
    observer->onAddToProjectionPlane(findedPlane, object->getProjection(findedPlane));
}

void Render::deleteFromPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object) {
    std::shared_ptr<ProjectionPlane> findedPlane = *planes.find(plane);
    planes.erase(findedPlane);
    object->deleteProjectionPlane(findedPlane);
}

void Render::changeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> oldObject,
                                       std::shared_ptr<Entity> newObject) {
    std::shared_ptr<ProjectionPlane> findedPlane = *planes.find(plane);

}

