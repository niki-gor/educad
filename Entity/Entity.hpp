#pragma once

#include "Utils.hpp"
#include "AngemEntity.h"
#include "TwoDEntity.h"
#include <cmath>
#include "iostream"
#include <set>

class ProjectionPlane;
class Plane;
class Line;
class Point;

class Entity {
private:
    std::set<PTR<ProjectionPlane> > projections;
public:
    virtual void update() = 0;
    virtual PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane) = 0;
    void addProjectionPlane(PTR<ProjectionPlane> plane){projections.insert(plane);}
    void deleteProjectionPlane(PTR<ProjectionPlane> plane){projections.erase(plane);}
};

namespace Utils{
    static Polyset<Entity> P; //Math. model
}

class Point : public Entity, public AngemPoint {
public:
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    PTR<Point> getProjectionOnLine(const PTR<Line>& line);
    PTR<Point> getProjectionOnPlane(const PTR<ProjectionPlane>& plane);
    double getDistance(PTR<Point> point);
};

class PointByCoords : public Point {
public:
    void update() {};
    PointByCoords(double x, double y, double z);
};

class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    void update() {};
    PointByLinesIntersection(PTR<Line> first, PTR<Line> second);
};


class Line : public Entity, public AngemLine {
public:
    PTR<Point> point1;
    PTR<Point> point2;
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    void update() {};
    LineByTwoPoints();
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
};

class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    LineByParallel();
    LineByParallel(const PTR<Point>& first, const PTR<Line>& second);
};

class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    LineByPerpendicular();
    LineByPerpendicular(const PTR<Point>& point, const PTR<Line>& line);
};

class LineByPlanesIntersection : public Line {
private:
    PTR<Plane> first;
    PTR<Plane> second;
public:
    void update() {};
    LineByPlanesIntersection();
    LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second);
};


class Plane : public Entity, public AngemPlane {

};

class PlaneByThreePoints : public Plane {
public:
    PTR<Point> first;
    PTR<Point> second;
    PTR<Point> third;
    PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>(new TwoDPoint(0,0));
    };
};
class PlaneByPointAndLine : public Plane {
public:
    PTR<Point> point;
    PTR<Line> line;
    PlaneByPointAndLine(PTR<Point> p, PTR<Line> l);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};
class PlaneByIntersectingLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};
class PlaneByParallelLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};

class ProjectionPlane : public Plane {
//private:
public:
    std::set<PTR<Entity> > projected;
    double xBegin;
    double yBegin;
    double zBegin;
    PTR<Point> originPoint;
    PTR<Line> absciss;
    PTR<Line> ordinat;

//public:
    ProjectionPlane(const PTR<Plane>& perpendicularPlane, PTR<Line> intersection);
    ProjectionPlane(PTR<Plane> plane);
    void add(PTR<Entity> object) {projected.insert(object);}
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>) {};
    void update(){};
};
