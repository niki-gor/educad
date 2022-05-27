#include "Entity.hpp"
#include "Angem.hpp"

LineByTwoPoints::LineByTwoPoints(PTR<Point> first, PTR<Point> second){
    this->first = first;
    this->second = second;
    init(first, second);
    first->addChild(MAKEPTR<LineByTwoPoints>(*this));
    second->addChild(MAKEPTR<LineByTwoPoints>(*this));
}

void LineByTwoPoints::init(PTR<Point> first, PTR<Point> second){
    this->i = second->x - first->x;
    this->j = second->y - first->y;
    this->k = second->z - first->z;
    this->x0 = second->x;
    this->y0 = second->y;
    this->z0 = second->z;
}

void LineByTwoPoints::update(){
    init(first, second);
    for(auto& i : children){
        i->update();
    }
}

std::vector<PTR<Entity>> LineByTwoPoints::getParents() const{
    std::vector<PTR<Entity>> parents = {first, second};
    return parents;
}

LineByParallel::LineByParallel(PTR<Point> first, PTR<Line> second){
    point = first;
    line = second;
    init(first, second);
    first->addChild(MAKEPTR<LineByParallel>(*this));
    second->addChild(MAKEPTR<LineByParallel>(*this));
}

void LineByParallel::init(PTR<Point> first, PTR<Line> second){
    i = second->i;
    j = second->j;
    k = second->k;
    x0 = first->x;
    y0 = first->y;
    z0 = first->z;
}

void LineByParallel::update(){
    init(point, line);
    for(auto& i : children){
        i->update();
    }
}

std::vector<PTR<Entity>> LineByParallel::getParents() const{
    std::vector<PTR<Entity>> parents = {point, line};
    return parents;
}


LineByPerpendicular::LineByPerpendicular(PTR<Point> point, PTR<Line> line){
    this->line = line;
    this->point = point;
    point->addChild(MAKEPTR<LineByPerpendicular>(*this));
    line->addChild(MAKEPTR<LineByPerpendicular>(*this));
}

void LineByPerpendicular::init(PTR<Point> point, PTR<Line> line){
    AngemLine l = AngemUtils::getPerpendicularLine(*point, *line);
    this->i = l.i;
    this->j = l.j;
    this->k = l.k;
    this->x0 = point->x;
    this->y0 = point->y;
    this->z0 = point->z;
}

void LineByPerpendicular::update(){
    AngemLine l = AngemUtils::getPerpendicularLine(*point, *line);
    init(point, line);
    for(auto& i : children){
        i->update();
    }
}

std::vector<PTR<Entity>> LineByPerpendicular::getParents() const{
    std::vector<PTR<Entity>> parents = {point, line};
    return parents;
}

LineByPlanesIntersection::LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second){ 
    this->first = first;
    this->second = second;
    init(first, second);
    first->addChild(MAKEPTR<LineByPlanesIntersection>(*this));
    second->addChild(MAKEPTR<LineByPlanesIntersection>(*this));
}

void LineByPlanesIntersection::init(PTR<Plane> first, PTR<Plane> second){
    AngemLine l = AngemUtils::planesIntersection(*first, *second);
    x0 = l.x0;
    y0 = l.y0;
    z0 = l.z0;
    i = l.i;
    j = l.j;
    k = l.k;
}

void LineByPlanesIntersection::update(){
    init(first,second);
    for(auto& i : children){
        i->update();
    }
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
