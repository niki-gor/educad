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
    void onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object) override;
};

#endif