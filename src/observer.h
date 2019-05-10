#ifndef OBSERVER_H
#define OBSERVER_H

#include "collection.cpp"
#include "token.h"
#include "observable.h"

template <typename T>
class Observer {
    protected:
        class InternalToken : public Token {
            private:
                Observer<T> _observer;
                Observable<T> _observable;
            public:
                InternalToken(Observer<T> observer, Observable<T> observable);
                void unsubscribe();
        };

        Collection<Observable<T>> _observervables;
    public:
        Observer();
        virtual Token subscribe(Observable<T> observable);
        virtual void next(T value);
};

#endif