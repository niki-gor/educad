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
#include <variant>
#include "vec3.h"

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

    static sf::View view;
    static float zoomFactor;

    static const float maxZoomFactor;
    static const float minZoomFactor;
    static const float zoomDeltaRatio;
public:
    static void init(std::unique_ptr<sf::RenderWindow>);
    static std::unique_ptr<sf::RenderWindow> window;

    static void increaseZoom();
    static void decreaseZoom();

    static void draw(const std::unordered_set<LinePtr, Hash>&, const std::unordered_set<PointPtr>&);

    static sf::CircleShape drawablePoint(const Point&);
    static sf::VertexArray drawableLine(const Line&);

    static std::variant<std::nullptr_t, PointPtr, LinePtr> cursorPointsTo(
        const std::unordered_set<PointPtr>& ,
        const std::unordered_set<LinePtr, Hash>&);

    static sf::Color randomColor();

    static Vec2 mapCoordsToNormal(sf::Vector2f);
    static sf::Vector2f mapNormalToCoords(Vec2);

    static Vec2 getCursorPosition();
};