#include <SFML/Graphics.hpp>
#include "utility.h"
#include "point.h"
#include "line.h"
#include <iostream>
#include <unordered_set>



int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Example", sf::Style::Fullscreen);
    sf::Cursor cursor;
    Utility utility(window);
    sf::VertexArray axes;
    utility.initAxes(axes, window);

    std::unordered_set<std::shared_ptr<Point>> points;
    std::unordered_set<std::shared_ptr<Line>> lines;

    std::unordered_set<std::shared_ptr<Point>> hiddenPoints;
    std::unordered_set<std::shared_ptr<Line>> hiddenLines;

    for (size_t i = 0; i < 10; ++i) {
        std::shared_ptr<Point> newPoint(new Point());
        newPoint->name = "lol";
        newPoint->pos = sf::Vector3f(rand() % 500, rand() % 500, rand() % 500);
        newPoint->color = sf::Color(utility.random() | 255);
        points.insert(newPoint);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    std::shared_ptr<Point> newPoint(new Point());
                    newPoint->name = "lol";
                    newPoint->pos.x = sf::Mouse::getPosition().x;
                    newPoint->pos.y = sf::Mouse::getPosition().y;
                    newPoint->color = sf::Color(utility.random() | 255);
                    points.insert(newPoint);
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    window.close();
                }
                break;
            };
        }

        auto pointedPoint = utility.cursorPointsToPoint(points, window);
        cursor.loadFromSystem(pointedPoint == nullptr ? sf::Cursor::Type::Arrow : sf::Cursor::Type::Hand);
        window.setMouseCursor(cursor);
        
        window.clear();

        window.draw(axes);

        for (auto& i : points) {
            window.draw(utility.drawablePoint(*i));
        }

        window.display();
    }

    return 0;
}