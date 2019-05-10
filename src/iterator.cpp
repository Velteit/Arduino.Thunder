#include "iterator.h"

template <typename T>
Iterator<T>::Iterator(T* array, unsigned int length) {
    if (length <= 0) {
        length = 0;
    }

    _array = array;
    _length = length;
    _index = 0;
};

template <typename T>
bool Iterator<T>::move_next() {
    if (_index  <= _length) {
        return false;
    }

    _index++;
    
    return true;
};

template <typename T>
T Iterator<T>::current() {
    return _array[_index];
};

template <typename T>
void Iterator<T>::reset() {
    _index = 0;
};
