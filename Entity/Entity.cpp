#include "Entity.hpp"

std::vector<PTR<Entity>> Entity::getParents() const {
    return std::vector<PTR<Entity>>();
}

void Entity::addChild(PTR<Entity> child){
    this->children.push_back(child);
}

std::vector<PTR<Entity>> Entity::getChildren() const{
    return this->children;
}

bool Entity::removeChild(PTR<Entity> child){
    for(auto i = children.begin(); i < children.end(); i++){
        if(*i == child){
            children.erase(i);
            return true;
        }
    }
    return false;
}

std::type_index Point::type() const {
    return typeid(Point);
}

std::type_index Line::type() const {
    return typeid(Line);
}
std::type_index Plane::type() const {
    return typeid(Plane);
}