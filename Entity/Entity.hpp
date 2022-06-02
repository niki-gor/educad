#pragma once

#include "utils.h"
#include "AngemEntity.h"
#include <cmath>
#include "iostream"
#include <set>
#include "polyset.h"
#include <vector>
#include "Angem.hpp"
#include "Renderable.h"
#include "string"

class ProjectionPlane;
class Plane;
class Line;
class Point;
class TwoDEntity;
class TwoDPoint;
class TwoDLine;
class Renderable;

class Entity {
public:
//private:
    std::set<PTR<ProjectionPlane> > projections;
    std::set<PTR<TwoDEntity>> twoDProjections;
    std::vector<PTR<Entity> > childrends;
//public:
    virtual void update() = 0;
    virtual PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane) = 0;
    void addProjectionPlane(const PTR<ProjectionPlane>& plane){projections.insert(plane);}
    void deleteProjectionPlane(PTR<ProjectionPlane> plane){projections.erase(plane);}
    virtual std::string type() const = 0;
    virtual std::vector<PTR<Entity> > getParents() const = 0;
    std::vector<PTR<Entity> > getChildren() const{return childrends;}
    void addChildren(PTR<Entity> children){ childrends.push_back(children);};
};

namespace Utils{
    static Polyset<Entity> P; //Math. model
}

class Point : public Entity, public AngemPoint {
public:
    std::string type() const {return "point";};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane) override;
    PTR<Point> getProjectionOnLine(const PTR<Line>& line);
    PTR<Point> getProjectionOnPlane(const PTR<Plane>& plane);
    PTR<TwoDPoint> getProjectionPoint(const PTR<ProjectionPlane>& projectionPlane);
    double getDistance(PTR<Point> point);
};

class PointByCoords : public Point {
public:
    void update() override {};
    PointByCoords(double x, double y, double z);
    std::vector<PTR<Entity> > getParents() const {return {};} ;
};

class PointOnLine : public Point{
public:
    void update() override {};
    PointOnLine(PTR<Line> line, double* x, double* y, double* z);
    std::vector<PTR<Entity> > getParents() const;
    PTR<Line> line;
};

class PointOnPlane : public Point{
public:
    PointOnPlane(PTR<Plane> plane, double* x, double* y, double* z);
    std::vector<PTR<Entity> > getParents() const;
    PTR<Plane> plane;
    void update() {};
};

class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    void update() {};
    PointByLinesIntersection(const PTR<Line>& first, const PTR<Line>& second);
    std::vector<PTR<Entity> > getParents() const;
};


class Line : public Entity, public AngemLine {
public:
    std::string type() const {return "line";};
    PTR<Point> point1;
    PTR<Point> point2;
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    PTR<TwoDLine> getProjectionLine(PTR<ProjectionPlane> projectionPlane);
};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    void update() {};
    LineByTwoPoints();
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
    std::vector<PTR<Entity> > getParents() const;
};

class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
    void setPoints(AngemPoint point1, AngemPoint point2);
public:
    void update() {};
    LineByParallel();
    std::vector<PTR<Entity> > getParents() const;
    LineByParallel(const PTR<Point>& first, const PTR<Line>& second);
};

class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() {};
    LineByPerpendicular();
    std::vector<PTR<Entity> > getParents() const;
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
    std::vector<PTR<Entity> > getParents() const;
};

class LineByParametres: public Line{
public:
    LineByParametres(double i, double j, double k, double x0, double y0, double z0);
    void update() {};
    std::vector<PTR<Entity> > getParents() const;
};

// Planes
class Plane : public Entity, public AngemPlane {
public:
    std::string type() const {return "plane";};
    virtual std::string planeType() const = 0;
    double getA(){return A;}
    double getB(){return B;}
    double getC(){return C;}
    double getD(){return D;}
};

class PlaneByThreePoints : public Plane {
public:
    PTR<Point> first;
    PTR<Point> second;
    PTR<Point> third;
    std::string planeType() const {return "planeByThreePoints";};
    PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

class PlaneByPointAndLine : public Plane {
public:
    PTR<Point> point;
    PTR<Line> line;
    std::string planeType() const {return "planeByPointAndLine";};
    PlaneByPointAndLine(PTR<Point> p, PTR<Line> l);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

class PlaneByIntersectingLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    std::string planeType() const {return "planeByIntersectinLines";};
    void update(){};
    PlaneByIntersectingLines(PTR<Line> l, PTR<Line> l1);
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

class PlaneByParallelLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    std::string planeType() const {return "planeByParallelLines";};
    PlaneByParallelLines(PTR<Line> l, PTR<Line> l1);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

//ProjectionPlane
class ProjectionPlane : public Plane {
//private:
public:
    std::set<PTR<TwoDEntity> > projected;
    PTR<Point> originPoint;
    PTR<Line> absciss;
    PTR<Line> ordinat;

//public:
    ProjectionPlane(const PTR<Plane>& plane);
    ProjectionPlane(double A, double B, double C, double D);
    std::string planeType() const {return "projectionPlane";}
    void add(PTR<TwoDEntity> object) {projected.insert(object);}
    void erase(PTR<TwoDEntity> object){projected.erase(object);}
    void update() override{};
    std::vector<PTR<Entity> > getParents() const {return {};}
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane){};
};

class TwoDEntity{
public:
    PTR<Renderable> renderable;
    PTR<ProjectionPlane> projectionPlane;
    PTR<Entity> projectedEntity;
    virtual void render() = 0;
    virtual void deleteFromRender() = 0;
    void setRenderable(PTR<Renderable> renderable_);
    virtual void setProjected(PTR<Entity> projected){projectedEntity = projected;}
    virtual void setProjectionPlane(PTR<ProjectionPlane> projectionPlane_){projectionPlane = projectionPlane_;}
    virtual PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) = 0;
};

class TwoDPoint : public TwoDEntity{
public:
    double X;
    double Y;
    TwoDPoint(double x, double y, PTR<ProjectionPlane> plane);
    void render();
    void deleteFromRender();

    PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) override;
};

class TwoDLine : public TwoDEntity{
private:
public:
    double getA() const;

    double getB() const;

    double getC() const;

private:
    double A;
    double B;
    double C;
public:
    std::shared_ptr<TwoDPoint> point1;
    std::shared_ptr<TwoDPoint> point2;
    TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2, PTR<ProjectionPlane> plane);
    void render();
    void deleteFromRender();

    PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) override;
};

class TwoDPlane: public TwoDEntity{
private:
public:
    const PTR<TwoDLine> &getLine1() const;

private:
    PTR<TwoDLine> line1;
    PTR<TwoDLine> line2;
    PTR<TwoDPoint> point1;
    PTR<TwoDPoint> point2;
    PTR<TwoDPoint> point3;
public:
    TwoDPlane(PTR<TwoDLine> line1_, PTR<TwoDLine> line2_): line1(line1_), line2(line2_){};
    TwoDPlane(PTR<TwoDLine> line, PTR<TwoDPoint> point_) : line1(line), point1(point_){};
    TwoDPlane(PTR<TwoDPoint> point1_, PTR<TwoDPoint> point2_ , PTR<TwoDPoint> point3_): point1(point1_), point2(point2_), point3(point3_){};
    void render() override;
    void setProjected(PTR<Entity> entity);
//    void setProjectionPlane(PTR<ProjectionPlane> projectionPlane_){}
    void deleteFromRender() override;

    PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) override;;
};

class Renderable{
public:
    virtual void addPoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name, TwoDPoint* twoDEntity) = 0;
    virtual void addLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) = 0;
    virtual void deletePoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name) = 0;
    virtual void deleteLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) = 0;
    virtual void addPlaneByLineAndPoint (int x, int y, int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name, TwoDEntity* twoDEntity)=0;
    virtual void addLinkLine(PTR<TwoDEntity> entity1, PTR<TwoDEntity> entity2) = 0;
};
