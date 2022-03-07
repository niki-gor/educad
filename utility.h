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
    static sf::VertexArray axes;
public:
    static std::unique_ptr<sf::RenderWindow> window;

    static void drawLines(const std::unordered_set<std::shared_ptr<Line>, Hash>&);
    static void drawPoints(const std::unordered_set<std::shared_ptr<Point>>&);
    static void drawAxes();

    static void init(std::unique_ptr<sf::RenderWindow>);
    static sf::CircleShape drawablePoint(const Point&);
    static sf::VertexArray drawableLine(const Line&);
    static std::shared_ptr<Point> cursorPointsToPoint(const std::unordered_set<std::shared_ptr<Point>>&);
    static std::shared_ptr<Line> cursorPointsToLine(const std::unordered_set<std::shared_ptr<Line>, Hash>&);
    static sf::Color randomColor();
};