#pragma once

#include <SFML/Graphics.hpp>
#include "point.h"
#include "line.h"
#include "hash.h"
#include "angem.h"
#include <random>
#include <chrono>
#include <unordered_set>
#include <iostream>

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

    static float pointRadius;
    static std::mt19937 random;
public:
    static void init(const sf::RenderWindow&);
    static sf::CircleShape drawablePoint(const Point&);
    static sf::VertexArray drawableLine(const Line&);
    static void initAxes(sf::VertexArray&, const sf::RenderWindow&);
    static std::shared_ptr<Point> cursorPointsToPoint(const std::unordered_set<std::shared_ptr<Point>>&, const sf::RenderWindow&);
    static std::shared_ptr<Line> cursorPointsToLine(const std::unordered_set<std::shared_ptr<Line>, Hash>&, const sf::RenderWindow&);
    static sf::Color randomColor();
};