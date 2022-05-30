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
    this->first = first;
    this->second = second;
    init(first, second);
    first->addChild(MAKEPTR<PointByLinesIntersection>(*this));
    second->addChild(MAKEPTR<PointByLinesIntersection>(*this));
}

void PointByLinesIntersection::init(PTR<Line> first, PTR<Line> second){
    AngemPoint p = AngemUtils::linesIntersection(*first, *second);
    x = p.x;
    y = p.y;
    z = p.z;
}

void PointByLinesIntersection::update(){
    init(first, second);
    for(auto& i : children){
        i->update();
    }
}

std::vector<PTR<Entity>> PointByLinesIntersection::getParents() const{
    std::vector<PTR<Entity>> parents = std::vector<PTR<Entity>>();
    parents.push_back(first);
    parents.push_back(second);
    return parents;
}

std::vector<PTR<Entity>> PointOnLine::getParents() const{
    std::vector<PTR<Entity>> parents = std::vector<PTR<Entity>>();
    parents.push_back(line);
    return parents;
}

PointOnLine::PointOnLine(PTR<Line> l1, double* x, double* y, double* z){
    AngemPoint p = AngemUtils::pointOnLine(*l1, x, y, z);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    line = l1;
}

void PointOnLine::update(){}

PointOnPlane::PointOnPlane(PTR<Plane> plane, double* x, double* y, double* z){
    AngemPoint p = AngemUtils::pointOnPlane(*plane, x, y, z);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    this->plane = plane;
}

void PointOnPlane::update(){
}

std::vector<PTR<Entity>> PointOnPlane::getParents() const{
    std::vector<PTR<Entity>> parents = std::vector<PTR<Entity>>();
    parents.push_back(plane);
    return parents;
}


