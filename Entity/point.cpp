#include "Entity.hpp"
#include "Angem.hpp"

double Point::getDistance(PTR<Point> point) {
    double squaredLength = (this->x - point->x)*(this->x - point->x) + (this->y - point->y)*(this->y - point->y) + (this->z - point->z)*(this->z - point->z);
    return sqrt(squaredLength);
}

PTR<TwoDPoint> Point::getProjectionPoint(const PTR<ProjectionPlane> &projectionPlane) {
    double pointX, pointY;
    PTR<Point> projectionOnPlane = getProjectionOnPlane(projectionPlane);
    PTR<Point> projectionOnAbsciss = projectionOnPlane->getProjectionOnLine(projectionPlane->absciss);
    PTR<Point> projectoinOnOrdinate = projectionOnPlane->getProjectionOnLine(projectionPlane->ordinat);
    pointX = projectionOnAbsciss->getDistance(projectionPlane->originPoint);
    pointY = projectoinOnOrdinate->getDistance(projectionPlane->originPoint);
    PTR<TwoDPoint> twoDPoint(new TwoDPoint(pointX, pointY, projectionPlane));
    projectionOnPlane.reset();
    projectionOnAbsciss.reset();
    projectoinOnOrdinate.reset();
    return twoDPoint;
}

std::vector<PTR<Entity> > Point::getChildren() const {

}

PointByCoords::PointByCoords(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

std::vector<PTR<Entity> > PointByCoords::getChildren() const {

}

PointByLinesIntersection::PointByLinesIntersection(PTR<Line> first, PTR<Line> second) {//не доделал
    AngemPoint p = AngemUtils::linesIntersection(*first, *second);
    x = p.x;
    y = p.y;
    z = p.z;
}

std::vector<PTR<Entity> > PointByLinesIntersection::getChildren() const{
    std::vector<PTR<Entity> > children = std::vector<PTR<Entity> >();
    children.push_back(first);
    children.push_back(second);
    return children;
}

std::vector<PTR<Entity> > PointOnLine::getChildren() const{
    std::vector<PTR<Entity> > children = std::vector<PTR<Entity> >();
    children.push_back(line);
    return children;
}

PointOnLine::PointOnLine(PTR<Line> l1, double x, double y, double z){
    
}

std::vector<PTR<Entity> > PointOnPlane::getChildren() const{
    std::vector<PTR<Entity> > children = std::vector<PTR<Entity> >();
    children.push_back(plane);
    return children;
}

