#ifndef IGUIOBSERVER_H
#define IGUIOBSERVER_H
#include "canvas.h"
#include <memory>
#include "GUIObserver.h"
//#include "../educad/Entity/Entity.hpp"

class GUIAPI : public GUIObserver {
protected:
    Canvas* canvas;
public:
    void onAddToProjectionPlane(std::shared_ptr<RenderableEntity> object) override;

    void onChangeFromProjectionPlane(std::shared_ptr<RenderableEntity> object) override;

    void onDeleteFromProjectionPlane(std::shared_ptr<RenderableEntity> object) override;
};

#endif