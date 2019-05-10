#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator {
    private:
        unsigned int _length;
        unsigned int _index;
        T* _array;

    public:
        Iterator(T* array, unsigned int length);
        bool move_next();
        T current();
        void reset();
};

#endif