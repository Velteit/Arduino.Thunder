#ifndef COLLECTION_H
#define COLLECTION_H

#include "iterator.h"

template <typename T>
class Collection {
    private:
        unsigned int _maxCount;
        unsigned int _currentCount;
        T* _array;
        unsigned int round(unsigned int input);

    public:
        Collection(T* input, unsigned int count);
        Collection();
        void add(T element);
        void remove(T element);
        Iterator<T> iterator();
        void remove(unsigned int index);
        void clear();
        void for_each(void (*handler)(T));
};

#endif