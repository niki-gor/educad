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

void Render::deleteFromPlane(const std::shared_ptr<ProjectionPlane>& plane, std::shared_ptr<Entity> object) {
    object->deleteProjectionPlane(plane);
    plane->erase(object);
    observer->onDeleteFromProjectionPlane(plane, object->getProjection(plane));
}

void Render::changeFromProjectionPlane(const std::shared_ptr<ProjectionPlane>& plane, std::shared_ptr<Entity> object) {
    observer->onChangeFromProjectionPlane(plane, object->getProjection(plane));
}

void Render::addProjectionPlane(const PTR<ProjectionPlane>& projectionPlane) {
    planes.insert(projectionPlane);
}

void Render::deleteProjectionPlane(const PTR<ProjectionPlane>& projectionPlane) {
    planes.erase(projectionPlane);
}

void Render::addEntity(const PTR<Entity>& entity) {
    for(const auto& it:entity->projections){
        it->add(entity);
        observer->onAddToProjectionPlane(it, entity->getProjection(it));
        planes.insert(it);
    }
}

void Render::deleteEntity(const PTR<Entity>& entity) {
    for (const auto& it:entity->projections){
        it->projected.erase(entity);
    }
}

Render::Render(PTR<GUIObserver> observer) {
    this->observer = observer;
}


