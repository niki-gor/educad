#pragma once

#include "utils.h"
#include "AngemEntity.h"
#include "TwoDEntity.h"
#include <cmath>
#include "iostream"
#include <set>
#include "polyset.h"
#include <vector>

class ProjectionPlane;
class Plane;
class Line;
class Point;

class Entity {
private:
    std::set<PTR<ProjectionPlane> > projections;
    
    // by niki-gor
    size_t calculateHash() const;
public:
    virtual ~Entity() = default;
    const size_t hash;
    PTR<Entity> fake;
    //

    virtual void update() = 0;
    virtual PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>) = 0;
    void addProjectionPlane(PTR<ProjectionPlane> plane){projections.insert(plane);}
    void deleteProjectionPlane(PTR<ProjectionPlane> plane){projections.erase(plane);}
    virtual std::type_index type() const = 0;
    virtual std::vector<PTR<Entity>> getParents() const;

    void addChild(PTR<Entity> child);
    bool removeChild(PTR<Entity> child);
    std::vector<PTR<Entity>> getChildren() const;


    std::vector<PTR<Entity>> children;
};

namespace Utils{
    static Polyset<Entity> P; //Math. model
}


class Point : public Entity, public AngemPoint {
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>);
    virtual std::type_index type() const override final{};
public:
    virtual ~Point(){};
};

class PointByCoords : public Point {
public:
    ~PointByCoords() = default;
    void update();
    PointByCoords(double x, double y, double z);
};

class PointOnLine : public Point{
public:
    ~PointOnLine() = default;
    void update();
    PointOnLine(PTR<Line> line, double x, double y, double z);
    std::vector<PTR<Entity>> getParents() const;
    PTR<Line> line;
};

class PointOnPlane : public Point{
public:
    ~PointOnPlane() = default;
    void update();
    PointOnPlane(PTR<Plane> plane, double x, double y, double z);
    std::vector<PTR<Entity>> getParents() const;
private:
    PTR<Plane> plane;
};

class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    ~PointByLinesIntersection() = default;
    void update();
    PointByLinesIntersection(PTR<Line> first, PTR<Line> second);
    std::vector<PTR<Entity>> getParents() const;
};


class Line : public Entity, public AngemLine {
    virtual std::type_index type() const override final{};
public:
    virtual ~Line(){};
};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    ~LineByTwoPoints() = default;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByTwoPoints();
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
    std::vector<PTR<Entity>> getParents() const;
};

class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    ~LineByParallel() = default;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByParallel();
    LineByParallel(PTR<Point> first, PTR<Line> second);
    std::vector<PTR<Entity>> getParents() const;
};

class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    ~LineByPerpendicular() = default;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByPerpendicular();
    LineByPerpendicular(PTR<Point> point, PTR<Line> line);
    std::vector<PTR<Entity>> getParents() const;
};

class LineByPlanesIntersection : public Line {
private:
    PTR<Plane> first;
    PTR<Plane> second;
public:
    ~LineByPlanesIntersection() = default;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByPlanesIntersection();
    LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second);
    std::vector<PTR<Entity>> getParents() const;
};


class Plane : public Entity, public AngemPlane {
    virtual std::type_index type() const override final{};
public:
    virtual ~Plane(){};
};

class PlaneByThreePoints : public Plane {
public:
    ~PlaneByThreePoints() = default;
    PTR<Point> first;
    PTR<Point> second;
    PTR<Point> third;
    PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3);
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>(new TwoDPoint(0,0));
    };
    std::vector<PTR<Entity>> getParents() const;
};

class PlaneByPointAndLine : public Plane {
public:
    ~PlaneByPointAndLine() = default;
    PTR<Point> point;
    PTR<Line> line;
    PlaneByPointAndLine(PTR<Point> p, PTR<Line> l);
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    std::vector<PTR<Entity>> getParents() const;
};

class PlaneByIntersectingLines : public Plane {
public:
    ~PlaneByIntersectingLines() = default;
    PTR<Line> first;
    PTR<Line> second;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    PlaneByIntersectingLines(PTR<Line> l, PTR<Line> l1);
    std::vector<PTR<Entity>> getParents() const;
};

class PlaneByParallelLines : public Plane {
public:
    ~PlaneByParallelLines() = default;
    PTR<Line> first;
    PTR<Line> second;
    PlaneByParallelLines(PTR<Line> l, PTR<Line> l1);
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    std::vector<PTR<Entity>> getParents() const;
};

class ProjectionPlane : public Plane {
private:
    std::set<PTR<Entity> > projected;
    double xBegin;
    double yBegin;
    double zBegin;
public:
    ProjectionPlane(PTR<ProjectionPlane> perpendicularProjection, PTR<Line> intersection);
    ProjectionPlane(PTR<Plane> plane);
    void add(PTR<Entity> object) {projected.insert(object);}
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>) {};
    void update(){};
};

#include "polyset.cpp"