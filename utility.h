#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "point.h"
#include "line.h"

class Utility {
private:
    static const float pointRadiusRatio;
    static const float outlineThicknessRatio;
    static const float pointRadiusChosenRatio;

    static const float maxPointingDeviationRatio;

    static const float axisOXLeftBoundRatio;
    static const float axisOXRightBoundRatio;
    static const float axisOYUpperBoundRatio;
    static const float axisOYLowerBoundRatio;
    static const float axisOZUpperBoundRatio;
    static const float axisOZLowerBoundRatio;



    const float pointRadius;
    const float pointingRadius;
public:
    Utility(const sf::RenderWindow&);
    sf::CircleShape drawablePoint(const Point);
    void initAxes(sf::VertexArray&, const sf::RenderWindow&);
    std::list<std::shared_ptr<Point>>::iterator cursorPointsToPoint(std::list<std::shared_ptr<Point>>&, const sf::RenderWindow&);

    sf::VertexArray drawableLine(const Line);
};