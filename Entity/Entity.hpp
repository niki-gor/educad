#include "Utils.hpp"
#include "Angem.hpp"
#include <cmath>

/*
class Entity {
private:
    Polymap<Projection, ProjectedEntity> projections;
    std::string name;
public:
    const Polymap<Projection, ProjectedEntity>& getProjections() const;
    PTR<ProjectedEntity> findProjection(PTR<Projection>);
    bool hasProjection(PTR<Projection>);
    void addProjection(PTR<Projection>);
};
*/

/*
class Model {
private:
    std::unordered_set<PTR<Observer>> observers;
public:
    void addObserver(PTR<Observer> observer) {
        observers.insert(observer);
    }
    void removeObserver(PTR<Observer> observer) {
        observers.erase(observer);
    }
};

class Observer {
public:
    virtual void onModelChanged() = 0;
    virtual ~Observer() {}
};

class AngemObserver : Observer {
public:
    void onModelChanged() override {

    };
};

int main() {
    Model model;

}


class ProjectedEntity {
private:
    PTR<Entity> entity;
    PTR<Projection> projection;
};
*/













class Entity {
private:
    std::set<PTR<Projection>> projections;
public:
    virtual void update() = 0;
};

class Point : public Entity {
};

class 

class ProjectionPlane : public Plane {
private:
    std::set<PTR<Entity>> projected;
public:
    ProjectionPlane(PTR<Projection> perpendicularProjection, PTR<Line> intersection);
};





class Projection : public AngemPlane {
private:
    std::set<PTR<Entity>> projected;
public:
    Projection() {}
    Projection(PTR<Projection> perpendicularProjection, PTR<Line> intersection);
    ProjectedPoint project(PTR<Point> point) const;
};


class Point : public Entity, public AngemPoint {
};

class PointByCoords : public Point {
public:
    PointByCoords(double x, double y, double z);
};
class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    PointByLinesIntersection(PTR<Line> first, PTR<Line> second);
}


class Line : public Entity, public AngemLine {

};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
}
class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    LineByParallel(PTR<Line> first, PTR<Line> second);
}
class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    LineByPerpendicular(PTR<Point> point, PTR<Line> line);
}
class LineByPlanesIntersection : public Line {
private:
    PTR<Plane> first;
    PTR<Plane> second;
public:
    LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second);
}


class Plane : public Entity, public AngemPlane;

class PlaneByThreePoints : public Plane;
class PlaneByPointAndLine : public Plane;
class PlaneByIntersectingLines : public Plane;
class PlaneByParallelLines : public Plane;









/*
class Plane : public Entity {
};

class ProjectedPlane : public ProjectedEntity {

};


class Plane : public Entity {

};


class Line : public Entity, public AngemLine {
    
};

class AngemEntity {
public:
    virtual bool isDefined() const = 0;
};

class AngemPoint : public AngemEntity {
public:
    double x;
    double y;
    double z;
    virtual bool isDefined() const override {
        return !std::isnan(x) && !std::isnan(y) && !std::isnan(z);
    }
};

class AngemLine : public AngemEntity {
public:
    double l;
    double m;
    double n;
    double x0;
    double y0;
    double z0;
    virtual bool isDefined() const override {
        return !std::isnan(l) && !std::isnan(m) && !std::isnan(n) && !std::isnan(x0) && !std::isnan(y0) && !std::isnan(z0);
    }
    AngemLine(double l, double m, double n, double x0, double y0, double z0) :
    l{l}, m{m}, n{n}, x0{x0}, y0{y0}, z0{z0} {}
};

class AngemParallelLine : public AngemLine {
public:
    AngemParallelLine(PTR<AngemPoint> point, PTR<AngemLine> line) : 
    AngemLine(line->l, line->m, line->n, point->x, point->y, point->z) {}
};

class ParallelLine : public Line {
public:
    ParallelLine(PTR<Point> point, PTR<Line> line) {
    }
};

class AngemPerpendicularLine : 

class PerpendicularLine : public Line {
public:
    PerpendicularLine(Point, Line);
};



class ProjectedEntity {
PTR<Projection> projection;
PTR<Entity> entity;
};
*/

















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