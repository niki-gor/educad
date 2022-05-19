#include "Entity.hpp"

std::vector<PTR<Entity>> Entity::getChildren() const {
    return std::vector<PTR<Entity>>();
}

std::vector<PTR<Entity> > Plane::getChildren() const {

}
