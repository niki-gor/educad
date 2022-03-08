#include "utility.h"

void Utility::init(std::unique_ptr<sf::RenderWindow> windowPtr) {
    srand(time(NULL));
    random.seed((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());

    window = std::move(windowPtr);
    window->setActive();

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
    result.setPosition(mapNormalToCoords(Vec2(point.pos)));
    result.setPointCount(5);    // pentagon

    result.setFillColor(sf::Color::Transparent);
    result.setRadius(pointRadius * (1 - outlineThicknessRatio));
    result.setOutlineColor(point.color);
    result.setOutlineThickness(pointRadius * outlineThicknessRatio);

    result.setOrigin(result.getRadius(), result.getRadius());
    return result;
}

std::variant<std::nullptr_t, PointPtr, LinePtr> Utility::cursorPointsTo(
    const std::unordered_set<PointPtr>& points,
    const std::unordered_set<LinePtr, Hash>& lines) {

    auto cursor = Point(Vec3(getCursorPosition()));
    using variant = std::variant<std::nullptr_t, PointPtr, LinePtr>;

    static const auto nearest = [&cursor](PointPtr point, LinePtr line)->variant {
        if (point != nullptr && line != nullptr) {
            if (Angem::fastDistance(*point, cursor) <= Angem::fastDistanceToBoundedLine(*line, cursor)) {
                return point;
            }
            return line;
        }
        if (point != nullptr)
            return point;
        if (line != nullptr)
            return line;
        return nullptr;
    };
    
    static const auto nearEnough = [&cursor](variant nearest)->variant {
        if (std::holds_alternative<PointPtr>(nearest)) {
            return (Angem::fastDistance(*std::get<PointPtr>(nearest), cursor) < pointRadius ? nearest : nullptr);
        }
        if (std::holds_alternative<LinePtr>(nearest)) {
            return (Angem::fastDistanceToBoundedLine(*std::get<LinePtr>(nearest), cursor) < pointRadius ? nearest : nullptr);
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
    result[0].position = mapNormalToCoords(Vec2(line.first->pos));
    result[0].color = line.first->color;
    result[1].position = mapNormalToCoords(Vec2(line.second->pos));
    result[1].color = line.second->color;
    return result;
}

sf::Color Utility::randomColor() {
    return sf::Color(random() | 255);
}

void Utility::draw(const std::unordered_set<LinePtr, Hash>& lines, const std::unordered_set<PointPtr>& points) {
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

Vec2 Utility::mapCoordsToNormal(sf::Vector2f coords) {
    return Vec2(coords.x, window->getSize().y - coords.y);
}

sf::Vector2f Utility::mapNormalToCoords(Vec2 point) {
    return sf::Vector2f(point.x, window->getSize().y - point.y);
}

Vec2 Utility::getCursorPosition() {
    return mapCoordsToNormal(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
}