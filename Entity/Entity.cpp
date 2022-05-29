#include "Entity.hpp"

size_t Entity::getHash() const {
    static const size_t prime = 1'000'000'007;
    auto result = typeid(*this).hash_code();
    for (auto& i : getParents()) {
        result = result * prime + i->getHash();
    }
    return result;
}

void TwoDEntity::setRenderable(PTR<Renderable> renderable_) {
    renderable = renderable_;
}
