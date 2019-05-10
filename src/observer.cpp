#include "observer.h"

template <typename T>
Observer<T>::InternalToken::InternalToken(Observer<T> observer, Observable<T> observable) {
    _observer = observer;
    _observable = observable;
};

template <typename T>
void Observer<T>::InternalToken::unsubscribe() {
    _observable._observervables.remove(_observer);
};


template <typename T>
Observer<T>::Observer() {
    _observervables = new Collection<Observable<T>>();
};

template <typename T>
Token Observer<T>::subscribe(Observable<T> observable) {
    _observervables.add(observable);

    return new Observer<T>::InternalToken(this, observable);
};

template <typename T>
void Observer<T>::next(T value) {
    _observervables.for_each([&](Observable<T> observable) { observable.on_next(value); });
};
