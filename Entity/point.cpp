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

PointByCoords::PointByCoords(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}

PointByLinesIntersection::PointByLinesIntersection(const PTR<Line>& first, const PTR<Line>& second) {
//    first->addChildren(PTR<Entity>(this));
//    first->addChildren(PTR<Entity>(this));
    AngemPoint p = AngemUtils::linesIntersection(*first, *second);
    x = p.x;
    y = p.y;
    z = p.z;
}

PointOnLine::PointOnLine(PTR<Line> l1, double* x, double* y, double* z){
    AngemPoint p = AngemUtils::pointOnLine(*l1, x, y, z);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    line = l1;
}

std::vector<PTR<Entity> > PointByLinesIntersection::getParents() const{
    return {first, second};
}

std::vector<PTR<Entity> > PointOnLine::getParents() const{
    return {line};
}

std::vector<PTR<Entity> > PointOnPlane::getParents() const {
    return {plane};
}

PointOnPlane::PointOnPlane(PTR<Plane> plane, double* x, double* y, double* z){
    AngemPoint p = AngemUtils::pointOnPlane(*plane, x, y, z);
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    this->plane = plane;
}


