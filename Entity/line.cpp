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

std::vector<PTR<Entity> > LineByParametres::getChildren() const {
}

std::vector<PTR<Entity> > Line::getChildren() const {

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
}

std::vector<PTR<Entity> > LineByTwoPoints::getChildren() const{
    std::vector<PTR<Entity> > children = {first, second};
    return children;
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
}

std::vector<PTR<Entity> > LineByParallel::getChildren() const{
    std::vector<PTR<Entity> > children = {point, line};
    return children;
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
}

std::vector<PTR<Entity> > LineByPerpendicular::getChildren() const{
    std::vector<PTR<Entity> > children = {point, line};
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

std::vector<PTR<Entity> > LineByPlanesIntersection::getChildren() const {
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

