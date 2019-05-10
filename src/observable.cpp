#include "observable.h"

template <typename T>
LambdaObservable<T>::LambdaObservable(void (*handler)(T)) {
    _handler = handler;
}


template <typename T>
void LambdaObservable<T>::on_next(T value) {
    _handler(value);
};
