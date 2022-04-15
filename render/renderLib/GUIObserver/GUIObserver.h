//
// Created by Марат Гасанов on 14.04.2022.
//

#ifndef RENDER_GUIOBSERVER_H
#define RENDER_GUIOBSERVER_H
#include "../../TwoDObject/TwoDObject.h"

class GUIObserver{
public:
    virtual void onAddToProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDObject> object) = 0;
    virtual void onChangeFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDObject> oldObject, std::shared_ptr<TwoDObject> newObject) = 0;
    virtual void onDeleteFromProjectionPlane(std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDObject> object) = 0;
};

#endif //RENDER_GUIOBSERVER_H
