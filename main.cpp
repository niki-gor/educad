#include <SFML/Graphics.hpp>
#include "utility.h"
#include "point.h"
#include "line.h"
#include <iostream>
#include <unordered_set>
#include "hash.h"



int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Example");
    sf::Cursor cursor;
    Utility::init(window);
    sf::VertexArray axes;
    Utility::initAxes(axes, window);

    std::unordered_set<std::shared_ptr<Point>> points;
    std::unordered_set<std::shared_ptr<Line>, Hash> lines;

    //std::unordered_set<std::shared_ptr<Point>> hiddenPoints;
    //std::unordered_set<std::shared_ptr<Line>> hiddenLines;

    for (size_t i = 0; i < 10; ++i) {
        points.emplace(new Point(sf::Vector3f(rand() % 500, rand() % 500, rand() % 500), Utility::randomColor()));
    }

    std::shared_ptr<Point> clickedPoint(nullptr);

    while (window.isOpen()) {
        auto pointedPoint = Utility::cursorPointsToPoint(points, window);

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (pointedPoint != nullptr) {
                        if (clickedPoint != nullptr && clickedPoint != pointedPoint) {
                            lines.emplace(new Line(clickedPoint, pointedPoint));
                            std::cout << "WAS HERE " << lines.size() << '\n';
                        }
                        clickedPoint = pointedPoint;
                    }
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    points.emplace(new Point(sf::Vector3f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 0), Utility::randomColor()));
                }
            };
        }

        cursor.loadFromSystem(pointedPoint == nullptr ? sf::Cursor::Type::Arrow : sf::Cursor::Type::Hand);
        window.setMouseCursor(cursor);
        
        window.clear();

        window.draw(axes);

        for (auto& i : lines) {
            window.draw(Utility::drawableLine(*i));
        }

        for (auto& i : points) {
            window.draw(Utility::drawablePoint(*i));
        }

        window.display();
    }

    for (auto& i : lines) {
        std::cout << i->first << ' ' << i->second << '\n';
    }

    return 0;
}