#ifndef IGUIOBSERVER_H
#define IGUIOBSERVER_H
#include "canvas.h"
#include <memory>
#include "GUIObserver.h"
//#include "../educad/Entity/Entity.hpp"

class GUIAPI : public GUIObserver {
public:
    PTR<Canvas> canvas;
    void onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object) override;
    void onChangeFromProjectionPlane(std::shared_ptr<TwoDEntity> object) override;
    void onDeleteFromProjectionPlane(std::shared_ptr<TwoDEntity> object) override;
    void onAddAlgorithm(std::vector<std::pair<std::string, std::vector<PTR<Entity>>>> algorithm) override;
};

#endif