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

    std::unordered_set<PointPtr> points;
    std::unordered_set<LinePtr, Hash> lines;

    std::unordered_set<PointPtr> chosenPoints;
    std::unordered_set<LinePtr> chosenLines;

    //std::unordered_set<PointPtr> hiddenPoints;
    //std::unordered_set<LinePtr> hiddenLines;

    for (size_t i = 0; i < 100; ++i)
        points.insert(std::make_shared<Point>(Vec3(rand() % 1000, rand() % 1000, 0), Utility::randomColor()));
    for (auto i = points.begin(); i != points.end(); std::advance(i, 2)) {
        lines.insert(std::make_shared<Line>(*i, *std::next(i)));
    }

    PointPtr clickedPoint(nullptr);

    while (Utility::window->isOpen()) {
        auto t0 = std::chrono::steady_clock::now();
        
        auto pointed = Utility::cursorPointsTo(points, lines);
        auto pointedPoint = std::get_if<PointPtr>(&pointed);
        auto pointedLine = std::get_if<LinePtr>(&pointed);
        
        sf::Event event;
        while (Utility::window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                Utility::window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (pointedPoint != nullptr) {
                        if (clickedPoint != nullptr && clickedPoint != *pointedPoint) {
                            lines.insert(std::make_shared<Line>(clickedPoint, *pointedPoint));                        }
                        clickedPoint = *pointedPoint;
                    }
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    points.insert(std::make_shared<Point>(Utility::getCursorPosition(), Utility::randomColor()));
                }
                break;
            case sf::Event::MouseWheelScrolled:
                if (event.mouseWheelScroll.delta < 0)
                    Utility::decreaseZoom();
                else
                    Utility::increaseZoom();
                break;
            case sf::Event::KeyPressed:
                for (auto& i : lines) {
                    i->first->color = sf::Color::Blue;
                    i->second->color = sf::Color::Yellow;
                }
                lines.clear();
                break;
            };
            event.mouseWheelScroll.delta = 0;
        }
        cursor.loadFromSystem(std::holds_alternative<nullptr_t>(pointed) ? sf::Cursor::Type::Arrow : sf::Cursor::Type::Hand);
        Utility::window->setMouseCursor(cursor);
        
        auto t1 = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << ' ';

        Utility::draw(lines, points);

        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t1).count() << '\n';
    }

    return 0;
}