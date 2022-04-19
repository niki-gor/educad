#pragma once

#include "Utils.hpp"
#include "AngemEntity.h"
#include "TwoDEntity.h"
#include <cmath>
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
    virtual PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>) = 0;
    void addProjectionPlane(PTR<ProjectionPlane> plane){projections.insert(plane);}
    void deleteProjectionPlane(PTR<ProjectionPlane> plane){projections.erase(plane);}
};

namespace Utils{
    static Polyset<Entity> P; //Math. model
}

//class

//class Projection : public AngemPlane {
//private:
//    std::set<PTR<Entity>> projected;
//public:
//    Projection() {}
//    Projection(PTR<Projection> perpendicularProjection, PTR<Line> intersection);
//    ProjectedPoint project(PTR<Point> point) const;
//};


class Point : public Entity, public AngemPoint {
};

class PointByCoords : public Point {
public:
    void update() {};
    PointByCoords(double x, double y, double z);
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};

class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    void update() {};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    PointByLinesIntersection(PTR<Line> first, PTR<Line> second);
};


class Line : public Entity, public AngemLine {

};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    void update() {};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByTwoPoints();
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
};

class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByParallel();
    LineByParallel(PTR<Point> first, PTR<Line> second);
};

class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
    LineByPerpendicular();
    LineByPerpendicular(PTR<Point> point, PTR<Line> line);
};

class LineByPlanesIntersection : public Line {
private:
    PTR<Plane> first;
    PTR<Plane> second;
public:
    void update() {};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
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
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};
class PlaneByPointAndLine : public Plane {
public:
    PTR<Point> point;
    PTR<Line> line;
    PlaneByPointAndLine(PTR<Point> p, PTR<Line> l);
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};
class PlaneByIntersectingLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};
class PlaneByParallelLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    void update();
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane>){
        return PTR<TwoDEntity>();
    };
};

class ProjectionPlane : public Plane {
private:
    std::set<PTR<Entity> > projected;
    double xBegin;
    double yBegin;
    double zBegin;
public:
    ProjectionPlane(PTR<ProjectionPlane> perpendicularProjection, PTR<Line> intersection);
    void add(PTR<Entity> object) {projected.insert(object);}
    void update();
};


















/*
class ProjectedEntity {
private:
    Polyset<ProjectedEntity> parents;
    Polyset<ProjectedEntity> children;
    PTR<Projection> projection;
    PTR<Entity> origin;
public:
    void addChild(PTR<ProjectedEntity> child);
    PTR<const Entity> getOrigin() const;
};

class Projection : public Entity {
private:
    PTR<AlgoLine> intersectionWithParent;
public:
    AlgoProjection(PTR<Line> intersectionWithParent);
    PTR<Line> getIntersectionWith(PTR<AlgoProjection> projection) const;

    template<class T>
    bool count(PTR<T> entity) const;
};
*/























/*
class AlgoEntity {
protected:
    Polyset<AlgoEntity> parents;
    Polyset<AlgoEntity> children;
public:
    const Polyset<AlgoEntity>& getParents() const;
    const Polyset<AlgoEntity>& getChildren() const;
    template<class T>
    void addChild(PTR<T> child);
};


class AlgoLine : public AlgoEntity {
};

class Point : public AlgoEntity, public AngemPoint {
public:
    Point(PTR<Line> first, PTR<Line> second) : AngemPoint(first, second);
};

class DrawablePoint : public sf::Drawable, public Point {
private:
    sf::CircleShape body;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

class DrawableLine : public sf::Drawable {
private:
    sf::VertexArray body;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

class Point : public Entity {
private:
    VEC2 position;
    Point(PTR<Projection> projection, VEC2 position);
public:
    Point(PTR<Line> first, PTR<Line> second);
    Point(float x, float y, float z);
    VEC2 getPosition() const;
};



class Line : public Entity {
public:
    Line(PTR<Point> first, PTR<Point> second);
    Line(PTR<Plane> first, PTR<Plane> second);
};



class Plane : public Entity {
public:
    Plane(PTR<Point> first, PTR<Point> second, PTR<Point> third);
    Plane(PTR<Line> first, PTR<Line> second);
    Plane(PTR<Point> point, PTR<Line> line);
};
*/