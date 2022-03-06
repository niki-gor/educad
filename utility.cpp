#include "utility.h"

Utility::Utility(const sf::RenderWindow& window) :
    pointRadius{ std::min(window.getSize().x, window.getSize().y) * pointRadiusRatio },
    pointingRadius{ std::min(window.getSize().x, window.getSize().y) * (pointRadiusRatio + maxPointingDeviationRatio) } {}

sf::CircleShape Utility::drawablePoint(const Point point) {
    sf::CircleShape result;
    result.setPosition(sf::Vector2f(point.pos.x, point.pos.y));
    result.setPointCount(10);

    result.setFillColor(sf::Color::Transparent);
    result.setRadius(pointRadius * (1 - outlineThicknessRatio));
    result.setOutlineColor(point.color);
    result.setOutlineThickness(pointRadius * outlineThicknessRatio);

    result.setOrigin(result.getRadius(), result.getRadius());
    return result;
}

std::list<std::shared_ptr<Point>>::iterator Utility::cursorPointsToPoint(std::list<std::shared_ptr<Point>>& points, const sf::RenderWindow& window) {
    auto result = points.end();
    auto cursor = sf::Mouse::getPosition(window);
    float minDistance = _HUGE_ENUF;
    for (auto i = points.begin(); i != points.end(); ++i) {
        auto distance = std::hypot(cursor.x - (*i)->pos.x, cursor.y - (*i)->pos.y);
        if (distance < minDistance) {
            minDistance = distance;
            result = i;
        }
    }
    if (std::hypot(cursor.x - (*result)->pos.x, cursor.y - (*result)->pos.y) > pointingRadius)
        return points.end();
    return result;
}

const float Utility::pointRadiusRatio = 0.007f;
const float Utility::outlineThicknessRatio = 0.2f;
const float Utility::pointRadiusChosenRatio = 0.01f;

const float Utility::maxPointingDeviationRatio = 0.002;

const float Utility::axisOXLeftBoundRatio = 0.2f;
const float Utility::axisOXRightBoundRatio = 0.8f;
const float Utility::axisOYUpperBoundRatio = 0.2f;
const float Utility::axisOZLowerBoundRatio = 0.8f;


void Utility::initAxes(sf::VertexArray& axes, const sf::RenderWindow& window) {
    const float width = (float)window.getSize().x;
    const float height = (float)window.getSize().y;
    axes.setPrimitiveType(sf::Lines);
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXLeftBoundRatio, height * 0.5f)));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * 0.5f)));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * axisOYUpperBoundRatio)));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * axisOZLowerBoundRatio)));
}

sf::VertexArray Utility::drawableLine(const Line line) {
    return sf::VertexArray();
}