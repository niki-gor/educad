#include <memory>

#include "Entity.hpp"
#include "Angem.hpp"

LineByParametres::LineByParametres(double i, double j, double k, double x0, double y0, double z0) {
    this->i = i;
    this->j = j;
    this->k = k;
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
}

LineByTwoPoints::LineByTwoPoints(PTR<Point> first, PTR<Point> second){
    this->point1 = first;
    this->point2 = second;
    this->first = first;
    this->second = second;
    this->i = second->x - first->x;
    this->j = second->y - first->y;
    this->k = second->z - first->z;
    this->x0 = second->x;
    this->y0 = second->y;
    this->z0 = second->z;
//    first->addChildren(PTR<Entity>(this));
//    second->addChildren(PTR<Entity>(this));
}

LineByParallel::LineByParallel(const PTR<Point>& first, const PTR<Line>& second){
    i = second->i;
    j = second->j;
    k = second->k;
    x0 = first->x;
    y0 = first->y;
    z0 = first->z;
    point = first;
    line = second;
    setPoints(*second->point1, *second->point2);
//    first->addChildren(PTR<Entity> (this));
//    second->addChildren(PTR<Entity> (this));
}

void LineByParallel::setPoints(AngemPoint point1, AngemPoint point2) {
    AngemPoint pointCoords1 = AngemUtils::getProjectionOnLine(*this, point1);
    AngemPoint pointCoords2 = AngemUtils::getProjectionOnLine(*this, point2);
    this->point1 = MAKEPTR<PointByCoords>(pointCoords1.x, pointCoords1.y, pointCoords1.z);
    this->point2 = MAKEPTR<PointByCoords>(pointCoords2.x, pointCoords2.y, pointCoords2.z);
}

LineByPerpendicular::LineByPerpendicular(const PTR<Point>& point, const PTR<Line>& line){
    this->line = line;
    this->point = point;
    AngemLine l = AngemUtils::getPerpendicularLine(*point, *line);
    this->i = l.i;
    this->j = l.j;
    this->k = l.k;
    this->x0 = point->x;
    this->y0 = point->y;
    this->z0 = point->z;
    this->point1 = point;
    AngemPoint point2Koords = AngemUtils::getProjectionOnLine(*line, *point);
    this->point2 = MAKEPTR<PointByCoords>(point2Koords.x, point2Koords.y, point2Koords.z);
//    point->addChildren(PTR<Entity> (this));
//    point->addChildren(PTR<Entity>(this));
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

std::vector<PTR<Entity> > LineByParametres::getParents() const {
    return {};
}

std::vector<PTR<Entity> > LineByTwoPoints::getParents() const{
    return {first, second};
}

std::vector<PTR<Entity> > LineByParallel::getParents() const{
    return {point, line};
}

std::vector<PTR<Entity> > LineByPerpendicular::getParents() const{
    return {point, line};
}

std::vector<PTR<Entity> > LineByPlanesIntersection::getParents() const {
    return {first, second} ;
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

