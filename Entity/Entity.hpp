#pragma once

#include "utils.h"
#include "AngemEntity.h"
#include "TwoDEntity.h"
#include <cmath>
#include "iostream"
#include <set>
#include "polyset.h"
#include <vector>
#include "Angem.hpp"

class ProjectionPlane;
class Plane;
class Line;
class Point;
class TwoDEntity;
class TwoDPoint;

class Entity {
public:
//private:
    std::set<PTR<ProjectionPlane> > projections;
//public:
    virtual void update() = 0;
    virtual PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane) = 0;
    void addProjectionPlane(const PTR<ProjectionPlane>& plane){projections.insert(plane);}
    void deleteProjectionPlane(PTR<ProjectionPlane> plane){projections.erase(plane);}
    virtual std::type_index type() const = 0;
    virtual std::vector<PTR<Entity> > getChildren() const;
};

namespace Utils{
    static Polyset<Entity> P; //Math. model
}

class Point : public Entity, public AngemPoint {
public:
    std::type_index type() const final{};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    PTR<Point> getProjectionOnLine(const PTR<Line>& line);
    PTR<Point> getProjectionOnPlane(const PTR<Plane>& plane);
    PTR<TwoDPoint> getProjectionPoint(const PTR<ProjectionPlane>& projectionPlane);
    double getDistance(PTR<Point> point);
    std::vector<PTR<Entity> > getChildren() const;
};

class PointByCoords : public Point {
public:
    void update() {};
    PointByCoords(double x, double y, double z);
    std::vector<PTR<Entity> > getChildren() const;
};

class PointOnLine : public Point{
public:
    void update() {};
    PointOnLine(PTR<Line> line, double x, double y, double z);
    std::vector<PTR<Entity> > getChildren() const;
    PTR<Line> line;
};

class PointOnPlane : public Point{
    PointOnPlane(PTR<Plane> plane);
    std::vector<PTR<Entity> > getChildren() const;
    PTR<Plane> plane;
};

class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    void update() {};
    PointByLinesIntersection(PTR<Line> first, PTR<Line> second);
    std::vector<PTR<Entity> > getChildren() const;
};


class Line : public Entity, public AngemLine {
public:
    std::type_index type() const override final {};
    PTR<Point> point1;
    PTR<Point> point2;
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getChildren() const;
};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    void update() {};
    LineByTwoPoints();
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
    std::vector<PTR<Entity> > getChildren() const;
};

class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    LineByParallel();
    std::vector<PTR<Entity> > getChildren() const;
    LineByParallel(const PTR<Point>& first, const PTR<Line>& second);
};

class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    LineByPerpendicular();
    std::vector<PTR<Entity> > getChildren() const;
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
    std::vector<PTR<Entity> > getChildren() const;
};

class LineByParametres: public Line{
public:
    LineByParametres(double i, double j, double k, double x0, double y0, double z0);
    void update() {};
    std::vector<PTR<Entity> > getChildren() const;
};

// Planes
class Plane : public Entity, public AngemPlane {
public:
    std::type_index type() const override final {};
    double getA(){return A;}
    double getB(){return B;}
    double getC(){return C;}
    double getD(){return D;}
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane){};
    std::vector<PTR<Entity> > getChildren() const;
};

class PlaneByThreePoints : public Plane {
public:
    PTR<Point> first;
    PTR<Point> second;
    PTR<Point> third;
    PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3);
    void update(){};
    std::vector<PTR<Entity> > getChildren() const;
};

class PlaneByPointAndLine : public Plane {
public:
    PTR<Point> point;
    PTR<Line> line;
    PlaneByPointAndLine(PTR<Point> p, PTR<Line> l);
    void update(){};
    std::vector<PTR<Entity> > getChildren() const;
};

class PlaneByIntersectingLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    void update(){};
    PlaneByIntersectingLines(PTR<Line> l, PTR<Line> l1);
    std::vector<PTR<Entity> > getChildren() const;
};

class PlaneByParallelLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    PlaneByParallelLines(PTR<Line> l, PTR<Line> l1);
    void update(){};
    std::vector<PTR<Entity> > getChildren() const;
};

//ProjectionPlane
class ProjectionPlane : public Plane {
//private:
public:
    std::set<PTR<Entity> > projected;
    PTR<Point> originPoint;
    PTR<Line> absciss;
    PTR<Line> ordinat;

//public:
    ProjectionPlane(const PTR<Plane>& plane);
    ProjectionPlane(double A, double B, double C, double D);
    void add(PTR<Entity> object) {projected.insert(object);}
    void erase(PTR<Entity> object){projected.erase(object);}
    void update(){};
    std::vector<PTR<Entity> > getChildren() const;
};

class TwoDEntity{
public:
    virtual void render() = 0;
    PTR<ProjectionPlane> projectionPlane;
};

class TwoDPoint : public TwoDEntity{
public:
    double X;
    double Y;
    TwoDPoint(double x, double y, PTR<ProjectionPlane> plane);
    void render();

};

class TwoDLine : public TwoDEntity{
private:
    double A;
    double B;
    double C;
    std::shared_ptr<TwoDPoint> point1;
    std::shared_ptr<TwoDPoint> point2;
public:
    TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2, PTR<ProjectionPlane> plane);
    void render();
};
