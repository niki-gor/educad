//
// Created by Марат Гасанов on 26.05.2022.
//
#include "Entity.hpp"

void TwoDPlane::render() {
    if (point){
        renderable->addPoint(point);
        renderable->addLine(line1);
    }
    else{
        renderable->addLine(line1);
        renderable->addLine(line2);
    }
}

void TwoDPlane::deleteFromRender() {

}

PTR<Entity> TwoDPlane::entityByTwoDEntity(PTR<TwoDEntity> secondProjection) {
    return PTR<Entity>();
}