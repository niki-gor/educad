//
// Created by Марат Гасанов on 26.05.2022.
//
#include "Entity.hpp"

void TwoDPlane::render() {
    if (point1 && point2){
//        renderable->addPoint(point1);
//        renderable->addPoint(point2);
//        renderable->addPoint(point3);
    }
    else if(line1 && point1){
//        renderable->addLine(point1);
//        renderable->addLine(line2);
    }
    else{
//        renderable->addLine(line1);
//        renderable->addLine(line2);
    }
}

void TwoDPlane::deleteFromRender() {

}

PTR<Entity> TwoDPlane::entityByTwoDEntity(PTR<TwoDEntity> secondProjection) {
    return PTR<Entity>();
}