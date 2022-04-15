#ifndef RENDER_LIBRARY_H
#define RENDER_LIBRARY_H
#include "../ProjectionPlane/ProjectionPlane.h"
#include "set"
#include "GUIObserver/GUIObserver.h"
#include "TwoDObject/TwoDObject.h"
#include "AngemEntity/AngemEntity.h"

class Render{
private:
    GUIObserver* observer;
    std::set<std::shared_ptr<ProjectionPlane>> planes;
public:
    void addToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<AngemEntity> object);
};

#endif //RENDER_LIBRARY_H
