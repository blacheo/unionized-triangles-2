#pragma once

template <typename T>
class StackList {
    T items[2];
    int size;
    void remove(int index);
};

template <typename T> void StackList<T>::remove(int index) {
    if (size > 1) {
        
    }
    size--;
}