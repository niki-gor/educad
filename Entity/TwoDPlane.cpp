//
// Created by Марат Гасанов on 26.05.2022.
//
#include "Entity.hpp"

void TwoDPlane::render() {
    if (point1 && point2){
        point1->render();
        point2->render();
        point3->render();
    }
    else if(line1 && point1){
        line1->render();
        point1->render();
    }
    else{
        line1->render();
        line2->render();
    }
}

void TwoDPlane::deleteFromRender() {
    if (point1 && point2){
        point1->deleteFromRender();
        point2->deleteFromRender();
        point3->deleteFromRender();
    }
    else if(line1 && point1){
        line1->deleteFromRender();
        point1->deleteFromRender();
    }
    else{
        line1->deleteFromRender();
        line2->deleteFromRender();
    }
}

void TwoDPlane::setProjected(PTR<Entity> entity) {
    projectedEntity = entity;
    if (point1 && point2){
        point1->projectedEntity = entity;
        point2->projectedEntity = entity;
        point3->projectedEntity = entity;
    }
    else if(line1 && point1){
        line1->projectedEntity = entity;
        point1->projectedEntity = entity;
    }
    else{
        line1->projectedEntity = entity;
        line2->projectedEntity = entity;
    }
}

PTR<Entity> TwoDPlane::entityByTwoDEntity(PTR<TwoDEntity> secondProjection) {
    return PTR<Entity>();
}
