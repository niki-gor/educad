//
// Created by Марат Гасанов on 14.04.2022.
//
#ifndef RENDER_GUIOBSERVER_H
#define RENDER_GUIOBSERVER_H
#include "Entity.hpp"
#include "Renderable.h"
#include "vector"
#include "string"

class GUIObserver{
public:
    virtual void onAddToProjectionPlane(std::shared_ptr<TwoDEntity> object) = 0;
    virtual void onChangeFromProjectionPlane(std::shared_ptr<TwoDEntity> object) = 0;
    virtual void onDeleteFromProjectionPlane(std::shared_ptr<TwoDEntity> object) = 0;
    virtual void onAddAlgorithm(std::vector<std::pair<std::string, std::vector<PTR<TwoDEntity>>>> algorithm) = 0;
};

#endif //RENDER_GUIOBSERVER_H
