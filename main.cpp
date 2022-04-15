#define DEBUG



#include <bits/stdc++.h>

#define TYPE(x) std::type_index(typeid(x))
#define MAKEPTR std::make_shared

template<class T>
using PTR = std::shared_ptr<T>;



template<class T>
class Polyset {
private:
    std::unordered_map<std::type_index, std::unordered_set<PTR<T>>> storage;
public:
    std::unordered_set<PTR<T>>& operator[](std::type_index type);

    void insert(PTR<T> key);

    void erase(PTR<T> key);

    bool count(PTR<T> key);

    size_t size() const;
};

template<class T>
std::unordered_set<PTR<T>>& Polyset<T>::operator[](std::type_index type) {
    return storage[type];
}

template<class T>
void Polyset<T>::insert(PTR<T> key) {
    storage[TYPE(*key)].insert(key);
}

template<class T>
void Polyset<T>::erase(PTR<T> key) {
    storage[TYPE(*key)].erase(key);
}

template<class T>
bool Polyset<T>::count(PTR<T> key) {
    return storage[TYPE(*key)].count(key);
}

template<class T>
size_t Polyset<T>::size() const {
    return storage.size();
}



class A {
public:
    void foo() {}
};

class B : public A {
public:
    void bar() {}
};

int main() {
    Polyset<A> ps;
    auto a = MAKEPTR<A>(A());
    auto b = MAKEPTR<A>(B());

    ps.insert(a);
    ps.insert(b);

    std::cout << ps.count(a) << "\n";
    std::cout << ps.count(b) << "\n";

    std::cout << ps[TYPE(A)].size() << "\n";
    std::cout << ps[TYPE(B)].size() << "\n";

    return 0;
}
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