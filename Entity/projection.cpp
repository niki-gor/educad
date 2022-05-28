//
// Created by Марат Гасанов on 15.05.2022.
//
#include "Entity.hpp"

PTR<TwoDEntity> Point::getProjection(PTR<ProjectionPlane> projectionPlane) {
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
    twoDProjections.insert(twoDPoint);
    twoDPoint->projectionPlane = projectionPlane;
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

PTR<TwoDEntity> Line::getProjection(PTR<ProjectionPlane> projectionPlane){
    PTR<TwoDPoint> twoDPoint1 = point1->getProjectionPoint(projectionPlane);
    PTR<TwoDPoint> twoDPoint2 = point2->getProjectionPoint(projectionPlane);
    PTR<TwoDLine> line(new TwoDLine(twoDPoint1, twoDPoint2, projectionPlane));
    line->projectionPlane = projectionPlane;
    twoDProjections.insert(line);
    return line;
}

PTR<TwoDLine> Line::getProjectionLine(PTR<ProjectionPlane> projectionPlane) {
    PTR<TwoDPoint> twoDPoint1 = point1->getProjectionPoint(projectionPlane);
    PTR<TwoDPoint> twoDPoint2 = point2->getProjectionPoint(projectionPlane);
    PTR<TwoDLine> line(new TwoDLine(twoDPoint1, twoDPoint2, projectionPlane));
    twoDProjections.insert(line);
    return line;
}

PTR<TwoDEntity> PlaneByThreePoints::getProjection(PTR<ProjectionPlane> projectionPlane) {
    PTR<TwoDPoint> point1Projected = first->getProjectionPoint(projectionPlane);
    PTR<TwoDPoint> point2Projected = second->getProjectionPoint(projectionPlane);
    PTR<TwoDPoint> point3Projected = third->getProjectionPoint(projectionPlane);
    PTR<TwoDEntity> projectedEntity(new TwoDPlane(point1Projected, point2Projected, point3Projected));
    point1Projected->projectionPlane = projectionPlane;
    point2Projected->projectionPlane = projectionPlane;
    point3Projected->projectionPlane = projectionPlane;
    return projectedEntity;
}

PTR<TwoDEntity> PlaneByPointAndLine::getProjection(PTR<ProjectionPlane> projectionPlane) {
    PTR<TwoDPoint> pointProjected = point->getProjectionPoint(projectionPlane);
    PTR<TwoDLine> lineProjected = line->getProjectionLine(projectionPlane);
    PTR<TwoDEntity> projectedEntity(new TwoDPlane(lineProjected, pointProjected));
    pointProjected->projectionPlane = projectionPlane;
    lineProjected->projectionPlane = projectionPlane;
    projectedEntity->projectionPlane = projectionPlane;
    return projectedEntity;
}

PTR<TwoDEntity> PlaneByIntersectingLines::getProjection(PTR<ProjectionPlane> projectionPlane) {
    PTR<TwoDLine> line1Projected = first->getProjectionLine(projectionPlane);
    PTR<TwoDLine> line2Projected = second->getProjectionLine(projectionPlane);
    PTR<TwoDEntity> projectedEntity(new TwoDPlane(line1Projected, line2Projected));
    line1Projected->projectionPlane = projectionPlane;
    line2Projected->projectionPlane = projectionPlane;
    return projectedEntity;
}

PTR<TwoDEntity> PlaneByParallelLines::getProjection(PTR<ProjectionPlane> projectionPlane) {
    PTR<TwoDLine> line1Projected = first->getProjectionLine(projectionPlane);
    PTR<TwoDLine> line2Projected = second->getProjectionLine(projectionPlane);
    PTR<TwoDEntity> projectedEntity(new TwoDPlane(line1Projected, line2Projected));
    line1Projected->projectionPlane = projectionPlane;
    line2Projected->projectionPlane = projectionPlane;
    return projectedEntity;
}

