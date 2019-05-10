#include "collection.h"
#include "iterator.h"

template <typename T>
unsigned int Collection<T>::round(unsigned int input) {
    // compute the next highest power of 2 of 32-bit v
    unsigned int v = input; 

    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;

    return v;
};

template <typename T>
Collection<T>::Collection() {
    _maxCount = 2;
    _currentCount = 0;
    _array = new T[_maxCount];
};

template <typename T>
Collection<T>::Collection(T* input, unsigned int count) {
    _array = input;
    _currentCount = count;
    _maxCount = round(count); 
};

template <typename T>
void Collection<T>::add(T element) {
    if (_currentCount + 1 > _maxCount) {
        T* temp = _array;
        unsigned int prevCount = _maxCount;
        _maxCount *= 2;
        _array = new T[_maxCount];

        for(unsigned int i = 0; i < prevCount; i++) {
            _array[i] = temp[i];
        }
        delete[] temp;
    }

    _currentCount++;
    _array[_currentCount + 1] = element;
};

template <typename T>
void Collection<T>::remove(T element) {
    for (unsigned int i = 0; i < _currentCount; i++) {
        if (_array[i] == element) {
            remove(i);
            break;
        }
    }
};

template <typename T>
void Collection<T>::remove(unsigned int index) {
    // [, _currentCount)
    if (0 <= index && index < _currentCount) {
        for (unsigned int i = index; i < _currentCount - 1; i++) {
            _array[i] = _array[i + 1];
        }

        delete _array[_currentCount - 1];
        _array[_currentCount - 1] = nullptr;
        _currentCount--;
    }
};

template <typename T>
void Collection<T>::clear() {
    delete[] _array;
    _maxCount = 2;
    _currentCount = 0;
    _array = new T[_maxCount];
};

template <typename T>
Iterator<T> Collection<T>::iterator() {
    return new Iterator<T>(_array, _currentCount);
};

template <typename T>
void Collection<T>::for_each(void (*handler)(T)) {
    for (auto i = 0; i < _currentCount; i++) {
        handler(_array[i]);
    }
};