#include "Entity.hpp"
#include "Angem.hpp"

PTR<TwoDEntity> Point::getProjection(PTR<ProjectionPlane> projectionPlane) {
    double pointX, pointY;
    PTR<Point> projectionOnPlane = getProjectionOnPlane(projectionPlane);
    PTR<Point> projectionOnAbsciss = projectionOnPlane->getProjectionOnLine(projectionPlane->absciss);
    PTR<Point> projectoinOnOrdinate = projectionOnPlane->getProjectionOnLine(projectionPlane->ordinat);
    pointX = projectionOnAbsciss->getDistance(projectionPlane->originPoint);
    pointY = projectoinOnOrdinate->getDistance(projectionPlane->originPoint);
    PTR<TwoDPoint> twoDPoint(new TwoDPoint(pointX, pointY));
    projectionOnPlane.reset();
    projectionOnAbsciss.reset();
    projectoinOnOrdinate.reset();
    return twoDPoint;
}

PTR<Point> Point::getProjectionOnLine(const PTR<Line>& line) {
    double pointX, pointY, pointZ;
    double tNumerator = (line->i*(this->x-line->x0) + line->j*(this->y-line->y0) + line->k*(this->z-line->z0));
    double tDenominator = (line->i*line->i + line->j*line->j + line->k*line->k);
    double t = (tNumerator/tDenominator);
    pointX = line->i*t + line->x0;
    pointY = line->j*t + line->y0;
    pointZ = line->k*t + line->z0;
    PTR<Point> point(new PointByCoords(pointX, pointY, pointZ));
    return point;
}

PTR<Point> Point::getProjectionOnPlane(const PTR<Plane>& plane) {
    double pointX, pointY, pointZ;
    double tNumerator = -(plane->A* this->x + plane->B*this->y + plane->C*this->z + plane->D);
    double tDenominator = (plane->A*plane->A + plane->B*plane->B + plane->C*plane->C);
    double t = (tNumerator/tDenominator);
    pointX = plane->A*t + this->x;
    pointY = plane->B*t + this->y;
    pointZ = plane->C*t + this->z;
    PTR<Point> point(new PointByCoords(pointX, pointY, pointZ));
    return point;
}

double Point::getDistance(PTR<Point> point) {
    double squaredLength = (this->x - this->x)*(this->x - this->x) + (this->y - this->y)*(this->y - this->y) + (this->z - this->z)*(this->z - this->z);
    return sqrt(squaredLength);
}

PTR<TwoDPoint> Point::getProjectionPoint(const PTR<ProjectionPlane> &projectionPlane) {
    double pointX, pointY;
    PTR<Point> projectionOnPlane = getProjectionOnPlane(projectionPlane);
    PTR<Point> projectionOnAbsciss = projectionOnPlane->getProjectionOnLine(projectionPlane->absciss);
    PTR<Point> projectoinOnOrdinate = projectionOnPlane->getProjectionOnLine(projectionPlane->ordinat);
    pointX = projectionOnAbsciss->getDistance(projectionPlane->originPoint);
    pointY = projectoinOnOrdinate->getDistance(projectionPlane->originPoint);
    PTR<TwoDPoint> twoDPoint(new TwoDPoint(pointX, pointY));
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

