#ifndef RENDER_LIBRARY_H
#define RENDER_LIBRARY_H
#include "set"
#include "GUIObserver/GUIObserver.h"
#include "TwoDObject.h"
#include "Entity.h"

class Render{
private:
    std::shared_ptr<GUIObserver> observer;
    std::set<std::shared_ptr<ProjectionPlane>> planes;
public:
    void addToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<AngemEntity> object);
};

#endif //RENDER_LIBRARY_H
