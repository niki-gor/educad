
/*
int main() {

    
    sf::Text text1()
    sf::RenderWindow window;
    sf::View view;
    // Initialize the view to a rectangle located at (100, 100) and with a size of 400x200
    view.reset(sf::FloatRect(100, 100, 400, 200));
    // Rotate it by 45 degrees
    view.rotate(45);
    // Set its target viewport to be half of the window
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
    // Apply it
    window.setView(view);
    // Render stuff
    window.draw(someSprite);
    // Set the default view back
    window.setView(window.getDefaultView());
    // Render stuff not affected by the view
    window.draw(someText);
    


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lol");

    Point p(nullptr, VEC2(300, 300));
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(shape);
        //window.draw(p);
        window.display();
    }


    return 0;
}*/