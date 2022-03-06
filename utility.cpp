#include "utility.h"

void Utility::init(const sf::RenderWindow& window) {
    pointRadius = std::min(window.getSize().x, window.getSize().y) * pointRadiusRatio;
    random.seed((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
}

sf::CircleShape Utility::drawablePoint(const Point& point) {
    sf::CircleShape result;
    result.setPosition(sf::Vector2f(point.pos.x, point.pos.y));
    result.setPointCount(5);    // pentagon

    result.setFillColor(sf::Color::Transparent);
    result.setRadius(pointRadius * (1 - outlineThicknessRatio));
    result.setOutlineColor(point.color);
    result.setOutlineThickness(pointRadius * outlineThicknessRatio);

    result.setOrigin(result.getRadius(), result.getRadius());
    return result;
}

std::shared_ptr<Point> Utility::cursorPointsToPoint(const std::unordered_set<std::shared_ptr<Point>>& points, const sf::RenderWindow& window) {
    auto cursor = sf::Mouse::getPosition(window);
    auto cursorPoint = Point(sf::Vector3f(cursor.x, cursor.y, 0));
    auto result = Angem::nearestPointToPoint(points, cursorPoint);
    if (result == nullptr) {
        return nullptr;
    }
    if (Angem::distance(*result, cursorPoint) > pointRadius) {
        return nullptr;
    }
    return result;
}

std::shared_ptr<Line> Utility::cursorPointsToLine(const std::unordered_set<std::shared_ptr<Line>, Hash>& lines, const sf::RenderWindow& window) {
    auto cursor = sf::Mouse::getPosition(window);
    auto cursorPoint = Point(sf::Vector3f(cursor.x, cursor.y, 0));
    auto result = Angem::nearestLineToPoint(lines, cursorPoint);
    if (result == nullptr) {
        return nullptr;
    }
    std::cout << Angem::distance(*result, cursorPoint) << ' ' << cursorPoint.pos.x << ' ' << cursorPoint.pos.y << '\n';
    if (Angem::distance(*result, cursorPoint) > pointRadius) {
        return nullptr;
    }
    return result;
}
        

const float Utility::pointRadiusRatio = 0.007f;
const float Utility::outlineThicknessRatio = 0.4f;
const float Utility::pointRadiusChosenRatio = 0.01f;

const float Utility::axisOXLeftBoundRatio = 0.2f;
const float Utility::axisOXRightBoundRatio = 0.8f;
const float Utility::axisOYUpperBoundRatio = 0.2f;
const float Utility::axisOZLowerBoundRatio = 0.8f;

float Utility::pointRadius;
std::mt19937 Utility::random;


void Utility::initAxes(sf::VertexArray& axes, const sf::RenderWindow& window) {
    const float width = (float)window.getSize().x;
    const float height = (float)window.getSize().y;
    axes.setPrimitiveType(sf::Lines);
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXLeftBoundRatio, height * 0.5f)));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * 0.5f)));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * axisOYUpperBoundRatio)));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * axisOZLowerBoundRatio)));
}

sf::VertexArray Utility::drawableLine(const Line& line) {
    sf::VertexArray result(sf::Lines, 2);
    result[0].position = { line.first->pos.x, line.first->pos.y };
    result[0].color = line.first->color;
    result[1].position = { line.second->pos.x, line.second->pos.y };
    result[1].color = line.second->color;
    return result;
}

sf::Color Utility::randomColor() {
    return sf::Color(random() | 255);
}