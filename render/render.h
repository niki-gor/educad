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
    void addToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object);
    void deleteFromPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object);
    void changeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<Entity> object);
};

#endif //RENDER_LIBRARY_H
