#include "utility.h"

void Utility::init(std::unique_ptr<sf::RenderWindow> windowPtr) {
    srand(time(NULL));
    random.seed((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());

    window = std::move(windowPtr);

    const float width = (float)window->getSize().x;
    const float height = (float)window->getSize().y;
    pointRadius = std::min(width, height) * pointRadiusRatio;
    axes.setPrimitiveType(sf::Lines);
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXLeftBoundRatio, height * 0.5f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * 0.5f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * axisOYUpperBoundRatio), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(width * axisOXRightBoundRatio, height * axisOZLowerBoundRatio), sf::Color::Black));

    zoomFactor = 1;
}

sf::CircleShape Utility::drawablePoint(const Point& point) {
    sf::CircleShape result;
    result.setPosition(mapPointToCoords(point));
    result.setPointCount(5);    // pentagon

    result.setFillColor(sf::Color::Transparent);
    result.setRadius(pointRadius * (1 - outlineThicknessRatio));
    result.setOutlineColor(point.color);
    result.setOutlineThickness(pointRadius * outlineThicknessRatio);

    result.setOrigin(result.getRadius(), result.getRadius());
    return result;
}

std::variant<std::nullptr_t, std::shared_ptr<Point>, std::shared_ptr<Line>> Utility::cursorPointsTo(
    const std::unordered_set<std::shared_ptr<Point>>& points,
    const std::unordered_set<std::shared_ptr<Line>, Hash>& lines) {

    auto cursor = getCursorPosition();
    using variant = std::variant<std::nullptr_t, std::shared_ptr<Point>, std::shared_ptr<Line>>;

    static const auto nearest = [&cursor](std::shared_ptr<Point> point, std::shared_ptr<Line> line)->variant {
        if (point != nullptr && line != nullptr) {
            if (Angem::distance(*point, cursor) <= Angem::fastDistanceToBoundedLine(*line, cursor)) {
                return point;
            }
            return line;
        }
        if (point == nullptr) {
            return line;
        }
        return point;
    };

    static const auto nearEnough = [&cursor](variant nearest)->variant {
        if (std::holds_alternative<std::shared_ptr<Point>>(nearest)) {
            return (Angem::fastDistance(*std::get<std::shared_ptr<Point>>(nearest), cursor) < pointRadius ? nearest : nullptr);
        }
        if (std::holds_alternative<std::shared_ptr<Line>>(nearest)) {
            return (Angem::fastDistance(*std::get<std::shared_ptr<Line>>(nearest), cursor) < pointRadius ? nearest : nullptr);
        }
        return nullptr;
    };

    return nearEnough(nearest(Angem::nearestPointToPoint(points, cursor), Angem::nearestLineToPoint(lines, cursor)));
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
sf::VertexArray Utility::axes;

sf::View Utility::view;
float Utility::zoomFactor;

const float Utility::maxZoomFactor = 4;
const float Utility::minZoomFactor = 0.2;
const float Utility::zoomDeltaRatio = 1.1;

std::unique_ptr<sf::RenderWindow> Utility::window;

sf::VertexArray Utility::drawableLine(const Line& line) {
    sf::VertexArray result(sf::Lines, 2);
    result[0].position = mapPointToCoords(*line.first);
    result[0].color = line.first->color;
    result[1].position = mapPointToCoords(*line.second);
    result[1].color = line.second->color;
    return result;
}

sf::Color Utility::randomColor() {
    return sf::Color(random() | 255);
}

void Utility::draw(const std::unordered_set<std::shared_ptr<Line>, Hash>& lines, const std::unordered_set<std::shared_ptr<Point>>& points) {
    window->clear(sf::Color::White);
    window->draw(axes);

    for (auto& i : lines) {
        window->draw(drawableLine(*i));
    }

    for (auto& i : points) {
        window->draw(drawablePoint(*i));
    }

    window->setView(view);
    window->display();
}

void Utility::increaseZoom() {
    if (zoomFactor / zoomDeltaRatio >= minZoomFactor) {
        zoomFactor /= zoomDeltaRatio;
        view.zoom(1 / zoomDeltaRatio);
    }
}

void Utility::decreaseZoom() {
    if (zoomFactor * zoomDeltaRatio <= maxZoomFactor) {
        zoomFactor *= zoomDeltaRatio;
        view.zoom(zoomDeltaRatio);
    }
}

Point Utility::mapCoordsToPoint(sf::Vector2f coords) {
    return Point(sf::Vector2f(coords.x, window->getSize().y - coords.y));
}

sf::Vector2f Utility::mapPointToCoords(Point point) {
    return sf::Vector2f(point.pos.x, window->getSize().y - point.pos.y);
}

Point Utility::getCursorPosition() {
    return mapCoordsToPoint(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
}