#ifndef RENDER_LIBRARY_H
#define RENDER_LIBRARY_H
#include "set"
#include "GUIObserver.h"
#include "TwoDEntity.h"
#include "Entity.hpp"

class Render{
private:
    std::set<std::shared_ptr<ProjectionPlane> > planes;
public:
    std::shared_ptr<GUIObserver> observer;
    Render(PTR<GUIObserver> observer);
    void addProjectionPlane(const PTR<ProjectionPlane>& projectionPlane);
    void deleteProjectionPlane(const PTR<ProjectionPlane>& projectionPlane);
    void addToProjectionPlane(const std::shared_ptr<ProjectionPlane>& plane, const std::shared_ptr<Entity>& object);
    void deleteFromPlane(const std::shared_ptr<ProjectionPlane>& plane, std::shared_ptr<Entity> object);
    void changeFromProjectionPlane(const std::shared_ptr<ProjectionPlane>& plane, std::shared_ptr<Entity> object);
    void deleteEntity(const PTR<Entity>& entity);
    void addEntity(const PTR<Entity>& entity);
};


#endif //RENDER_LIBRARY_H