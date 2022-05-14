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
}

std::vector<PTR<Entity>> LineByTwoPoints::getChildren() const{
    std::vector<PTR<Entity>> children = {first, second};
    return children;
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
}

std::vector<PTR<Entity>> LineByParallel::getChildren() const{
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
}

std::vector<PTR<Entity>> LineByPerpendicular::getChildren() const{
    std::vector<PTR<Entity>> children = {point, line};
    return children;
}

LineByPlanesIntersection::LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second){ //Не дописал
    this->first = first;
    this->second = second;
    x0 = 1;
    y0 = 1;
    z0 = 1;
    i = 1;
    j = 1;
    k = 1;
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
