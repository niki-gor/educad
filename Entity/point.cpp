#include "Entity.hpp"
#include "Angem.hpp"

PTR<TwoDEntity> Point::getProjection(PTR<ProjectionPlane>) {
    PTR<TwoDEntity> entity(new TwoDPoint(1,2));
    return entity;
}

PointByCoords::PointByCoords(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

void PointByCoords::update(){};

PointByLinesIntersection::PointByLinesIntersection(PTR<Line> first, PTR<Line> second) {
    AngemPoint p = AngemUtils::linesIntersection(*first, *second);
    this->first = first;
    this->second = second;
    x = p.x;
    y = p.y;
    z = p.z;
    first->addChild(MAKEPTR<PointByLinesIntersection>(*this));
    second->addChild(MAKEPTR<PointByLinesIntersection>(*this));
}

void PointByLinesIntersection::update(){
    AngemPoint p = AngemUtils::linesIntersection(*first, *second);
    x = p.x;
    y = p.y;
    z = p.z;
}

std::vector<PTR<Entity>> PointByLinesIntersection::getParents() const{
    std::vector<PTR<Entity>> children = std::vector<PTR<Entity>>();
    children.push_back(first);
    children.push_back(second);
    return children;
}

std::vector<PTR<Entity>> PointOnLine::getParents() const{
    std::vector<PTR<Entity>> children = std::vector<PTR<Entity>>();
    children.push_back(line);
    return children;
}

PointOnLine::PointOnLine(PTR<Line> l1, double x, double y, double z){
    AngemPoint p = AngemUtils::pointOnLine(*l1, x, y, z);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    line = l1;
    l1->addChild(MAKEPTR<PointOnLine>(*this));
}

void PointOnLine::update(){
    AngemPoint p = AngemUtils::pointOnLine(*line, line->x0, line->y0, NULL);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

PointOnPlane::PointOnPlane(PTR<Plane> plane, double x, double y, double z){
    AngemPoint p = AngemUtils::pointOnPlane(*plane, x, y, z);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    this->plane = plane;
    plane->addChild(MAKEPTR<PointOnPlane>(*this));
}

void PointOnPlane::update(){
    this->plane = nullptr;
}

std::vector<PTR<Entity>> PointOnPlane::getParents() const{
    std::vector<PTR<Entity>> children = std::vector<PTR<Entity>>();
    children.push_back(plane);
    return children;
}


