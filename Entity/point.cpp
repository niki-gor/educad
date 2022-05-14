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

PointByLinesIntersection::PointByLinesIntersection(PTR<Line> first, PTR<Line> second) {//не доделал
    AngemPoint p = AngemUtils::linesIntersection(*first, *second);
    x = p.x;
    y = p.y;
    z = p.z;
}

std::vector<PTR<Entity>> PointByLinesIntersection::getChildren() const{
    std::vector<PTR<Entity>> children = std::vector<PTR<Entity>>();
    children.push_back(first);
    children.push_back(second);
    return children;
}

std::vector<PTR<Entity>> PointOnLine::getChildren() const{
    std::vector<PTR<Entity>> children = std::vector<PTR<Entity>>();
    children.push_back(line);
    return children;
}

PointOnLine::PointOnLine(PTR<Line> l1, double x, double y, double z){
    
}

std::vector<PTR<Entity>> PointOnPlane::getChildren() const{
    std::vector<PTR<Entity>> children = std::vector<PTR<Entity>>();
    children.push_back(plane);
    return children;
}


