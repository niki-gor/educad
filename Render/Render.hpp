#include <SFML/Graphics.hpp>
#include "Entity.hpp"



class RenderEntity : public Entity, public Drawable {

};
class RenderPoint : public
class Render : public sf::Drawable {
private:
    sf::VertexArray vertexArray;
    sf::CircleShape circleShape;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Render(PTR<Point> point);
    Render(PTR<Line> line);
    Render(PTR<Projection> projection);
};