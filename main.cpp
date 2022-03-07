#include <SFML/Graphics.hpp>
#include "utility.h"
#include "point.h"
#include "line.h"
#include <iostream>
#include <unordered_set>
#include "hash.h"



int main() {
    sf::Cursor cursor;
    Utility::init(std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 1000), "Lol"));

    std::unordered_set<std::shared_ptr<Point>> points;
    std::unordered_set<std::shared_ptr<Line>, Hash> lines;

    //std::unordered_set<std::shared_ptr<Point>> hiddenPoints;
    //std::unordered_set<std::shared_ptr<Line>> hiddenLines;

    for (size_t i = 0; i < 10; ++i) {
        points.insert(std::make_shared<Point>(sf::Vector3f(rand() % 500, rand() % 500, rand() % 500), Utility::randomColor()));
    }

    std::shared_ptr<Point> clickedPoint(nullptr);

    while (Utility::window->isOpen()) {
        auto pointedPoint = Utility::cursorPointsToPoint(points);
        auto pointedLine = Utility::cursorPointsToLine(lines);

        sf::Event event;
        while (Utility::window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                Utility::window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (pointedPoint != nullptr) {
                        if (clickedPoint != nullptr && clickedPoint != pointedPoint) {
                            lines.insert(std::make_shared<Line>(clickedPoint, pointedPoint));
                            std::cout << "WAS HERE " << lines.size() << '\n';
                        }
                        clickedPoint = pointedPoint;
                    }
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    points.insert(std::make_shared<Point>(sf::Vector3f(sf::Mouse::getPosition(*Utility::window).x, sf::Mouse::getPosition(*Utility::window).y, 0), Utility::randomColor()));
                }
                break;
            case sf::Event::MouseWheelScrolled:
                if (event.mouseWheelScroll.delta < 0)
                    Utility::decreaseZoom();
                else
                    Utility::increaseZoom();
                break;
            };
            event.mouseWheelScroll.delta = 0;
        }

        cursor.loadFromSystem(pointedPoint == nullptr && pointedLine == nullptr ? sf::Cursor::Type::Arrow : sf::Cursor::Type::Hand);
        Utility::window->setMouseCursor(cursor);

        Utility::draw(lines, points);
    }

    return 0;
}