//#pragma once

#include "polyset.h"



template<class T>
std::unordered_set<PTR<T> >& Polyset<T>::operator[](std::type_index type) {
    return storage[type];
}

template<class T>
void Polyset<T>::insert(PTR<T> key) {
    storage[key->type()].insert(key);
}

template<class T>
Polyset<T>& Polyset<T>::add(PTR<T> key) {
    insert(key);
    return *this;
} 

template<class T>
void Polyset<T>::erase(PTR<T> key) {
    storage[key->type()].erase(key);
}

template<class T>
bool Polyset<T>::count(PTR<T> key) {
    return storage[key->type()].count(key);
}