#include <SFML/Graphics.hpp>
#include "utility.h"
#include "point.h"
#include "line.h"
#include <iostream>
#include <list>



int main() {
    srand((unsigned int)time(NULL));
    sf::RenderWindow window(sf::VideoMode(500, 500), "Example", sf::Style::Fullscreen);
    sf::Cursor cursor;
    Utility utility(window);
    sf::VertexArray axes;
    utility.initAxes(axes, window);
    
    std::list<std::shared_ptr<Point>> points;
    std::list<std::shared_ptr<Line>> lines;

    std::list<std::shared_ptr<Point>> hiddenPoints;
    std::list<std::shared_ptr<Line>> hiddenLines;

    for (size_t i = 0; i < 10; ++i) {
        points.emplace_back(new Point());
        points.back()->name = "lol";
        points.back()->pos = sf::Vector3f(rand() % 500, rand() % 500, rand() % 500);
        points.back()->color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
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
                    points.emplace_back(new Point());
                    points.back()->pos.x = sf::Mouse::getPosition().x;
                    points.back()->pos.y = sf::Mouse::getPosition().y;
                    points.back()->color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
                    points.back()->name = "lolol";
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    window.close();
                }
                break;
            };
        }

        auto pointedPoint = utility.cursorPointsToPoint(points, window);
        cursor.loadFromSystem(pointedPoint == points.end() ? sf::Cursor::Type::Arrow : sf::Cursor::Type::Hand);
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