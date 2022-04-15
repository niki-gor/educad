#include "Entity.hpp"

























/*

Entity::~Entity() {}

Entity::Entity(Polyset<Entity> parents) : parents{parents} {}

Point::Point(PTR<Projection> projection, VEC2 position, Polyset<Entity> parents) : 



Point::Point(PTR<Projection> projection, VEC2 position) : Entity(projection), position{position} {
    projection->insert(PTR<Point>(this));
}

void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::CircleShape result;
    result.setPosition(position);
    result.setFillColor(sf::Color::Transparent);
    result.setRadius(3);
    result.setOutlineColor(sf::Color::Black);
    result.setOutlineThickness(2);
    result.setOrigin(result.getRadius(), result.getRadius());

    target.draw(result);
}

VEC2 Point::getPosition() const {
    return position;
}

Line::Line(PTR<Projection> projection, PTR<Point> first, PTR<Point> second) : Entity(projection), first{first}, second{second} {
    projection->insert(PTR<Line>(this));
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::VertexArray result(sf::Lines, 2);
    result[0].position = first->getPosition();
    result[0].color = sf::Color::Black;
    result[1].position = second->getPosition();
    result[1].color = sf::Color::Black;

    target.draw(result);
}

*/








/*
class Entity {
protected:
    PTR<Projection> projection;
    Polyset<Entity> parents;
    Polyset<Entity> children;
public:
    virtual void draw() const = 0;
    virtual ~Entity();
};



class Point : public Entity {
private:
    VEC2 position;
public:
    Point(PTR<Projection> projection, VEC2 position);
    void draw() const override;
};



class Line : public Entity {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    Line(PTR<Point> first, PTR<Point> second);
    void draw() const override;
};



class Plane : public Entity {
private:
    PTR<Point> first;
    PTR<Point> second;
    PTR<Point> third;
public:
    void draw() const override;
};
*/