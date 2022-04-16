//
// Created by Марат Гасанов on 14.04.2022.
//

#ifndef RENDER_GUIOBSERVER_H
#define RENDER_GUIOBSERVER_H
#include "TwoDEntity.h"

class GUIObserver{
public:
    virtual void onAddToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object) = 0;
    virtual void onChangeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDObject> newObject) = 0;
    virtual void onDeleteFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object) = 0;
};

#endif //RENDER_GUIOBSERVER_H
