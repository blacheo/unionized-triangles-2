#pragma once
#include <optional>

template<typename T>
class StaticVector{
    int size = 0;
    public:

    T items [2];
    int getSize() const;
    void clear();
    void push_back(T item);
    void push_back(std::optional<T> item);
};

template<typename T> void StaticVector<T>::push_back(T item) {
    items[size] = item;
    size++;
}

template<typename T> void StaticVector<T>::push_back(std::optional<T> item) {
   if (item.has_value()) {
    this->push_back(item.value);
   } 
}

template<typename T> int StaticVector<T>::getSize() const {
    return size;
}

template<typename T> void StaticVector<T>::clear() {
    size = 0;
}