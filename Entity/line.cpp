#include "Entity.hpp"
#include "Angem.hpp"

LineByTwoPoints::LineByTwoPoints(PTR<Point> first, PTR<Point> second){
    this->first = first;
    this->second = second;
    this->i = second->x - first->x;
    this->j = second->y - first->y;
    this->k = second->z - first->z;
    this->x0 = second->x;
    this->y0 = second->y;
    this->z0 = second->z;
    first->addChild(MAKEPTR<LineByTwoPoints>(*this));
    second->addChild(MAKEPTR<LineByTwoPoints>(*this));
}

void LineByTwoPoints::update(){
    this->i = second->x - first->x;
    this->j = second->y - first->y;
    this->k = second->z - first->z;
    this->x0 = second->x;
    this->y0 = second->y;
    this->z0 = second->z;
}

std::vector<PTR<Entity>> LineByTwoPoints::getParents() const{
    std::vector<PTR<Entity>> parents = {first, second};
    return parents;
}

LineByParallel::LineByParallel(PTR<Point> first, PTR<Line> second){
    i = second->i;
    j = second->j;
    k = second->k;
    x0 = first->x;
    y0 = first->y;
    z0 = first->z;
    point = first;
    line = second;
    first->addChild(MAKEPTR<LineByParallel>(*this));
    second->addChild(MAKEPTR<LineByParallel>(*this));
}

void LineByParallel::update(){
    i = line->i;
    j = line->j;
    k = line->k;
    x0 = point->x;
    y0 = point->y;
    z0 = point->z;
}

std::vector<PTR<Entity>> LineByParallel::getParents() const{
    std::vector<PTR<Entity>> children = {point, line};
    return children;
}


LineByPerpendicular::LineByPerpendicular(PTR<Point> point, PTR<Line> line){
    this->line = line;
    this->point = point;
    AngemLine l = AngemUtils::getPerpendicularLine(*point, *line);
    this->i = l.i;
    this->j = l.j;
    this->k = l.k;
    this->x0 = point->x;
    this->y0 = point->y;
    this->z0 = point->z;
    point->addChild(MAKEPTR<LineByPerpendicular>(*this));
    line->addChild(MAKEPTR<LineByPerpendicular>(*this));
}

void LineByPerpendicular::update(){
    AngemLine l = AngemUtils::getPerpendicularLine(*point, *line);
    this->i = l.i;
    this->j = l.j;
    this->k = l.k;
    this->x0 = point->x;
    this->y0 = point->y;
    this->z0 = point->z;
}

std::vector<PTR<Entity>> LineByPerpendicular::getParents() const{
    std::vector<PTR<Entity>> children = {point, line};
    return children;
}

LineByPlanesIntersection::LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second){ 
    this->first = first;
    this->second = second;
    AngemLine l = AngemUtils::planesIntersection(*first, *second);
    x0 = l.x0;
    y0 = l.y0;
    z0 = l.z0;
    i = l.i;
    j = l.j;
    k = l.k;
    first->addChild(MAKEPTR<LineByPlanesIntersection>(*this));
    second->addChild(MAKEPTR<LineByPlanesIntersection>(*this));
}

void LineByPlanesIntersection::update(){
    AngemLine l = AngemUtils::planesIntersection(*first, *second);
    x0 = l.x0;
    y0 = l.y0;
    z0 = l.z0;
    i = l.i;
    j = l.j;
    k = l.k;
}

std::vector<PTR<Entity>> LineByPlanesIntersection::getParents() const{
    return {first, second};
}

LineByPlanesIntersection::LineByPlanesIntersection(){
    x0 = 1;
    y0 = 1;
    z0 = 1;
    i = 1;
    j = 1;
    k = 1;
}

LineByTwoPoints::LineByTwoPoints(){ 
    x0 = 1;
    y0 = 1;
    z0 = 1;
    i = 1;
    j = 1;
    k = 1;
}

LineByParallel::LineByParallel(){
    x0 = 1;
    y0 = 1;
    z0 = 1;
    i = 1;
    j = 1;
    k = 1;
}

LineByPerpendicular::LineByPerpendicular(){
    x0 = 1;
    y0 = 1;
    z0 = 1;
    i = 1;
    j = 1;
    k = 1;
}
