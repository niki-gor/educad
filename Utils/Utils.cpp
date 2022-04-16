#include "Utils.hpp"



template<class T>
std::unordered_set<PTR<T> >& Polyset<T>::operator[](std::type_index type) {
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