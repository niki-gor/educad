#pragma once

#include <typeindex>
#include <typeinfo>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include "Entity.hpp"

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

namespace Utils{
    static Polyset<Entity> P; //Math. model
}