#pragma once

#include <unordered_set>
#include <unordered_map>
#include "utils.h"



template<class T>
class Polyset {
private:
    std::unordered_map<std::type_index, std::unordered_set<PTR<T> > > storage;
public:
    std::unordered_set<PTR<T> >& operator[](std::type_index type);
    void insert(PTR<T> key);
    Polyset<T>& add(PTR<T> key);
    void erase(PTR<T> key);
    bool count(PTR<T> key);
};

//#include "polyset.cpp"