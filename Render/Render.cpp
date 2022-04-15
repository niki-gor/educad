#include "Render.hpp"



void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(vertexArray);
    target.draw(circleShape);
}