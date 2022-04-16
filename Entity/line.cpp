//
// Created by Марат Гасанов on 16.04.2022.
//

#include "Entity.hpp"

LineByTwoPoints::LineByTwoPoints(PTR<Point> first, PTR<Point> second){
    this->first = first;
    this->second = second;
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

LineByPerpendicular::LineByPerpendicular(PTR<Point> point, PTR<Line> line){
    x0 = point->x;
    y0 = point->y;
    z0 = point->z;
    this->point = point;
    this->i = 1;
    this->j = 1;
    this->k = (-line->i - line->j)/line->k;
    this->line = line;
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