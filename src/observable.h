#ifndef OBSERVABLE_H
#define OBSERVABLE_H

template <typename T>
class Observable {
    protected:
    public:
        virtual void on_next(T value);
        virtual void on_complete();
};

template <typename T>
class LambdaObservable : public Observable<T> {
    protected:
        void (*_handler)(T);
    public:
        LambdaObservable(void (*handler)(T));
        void on_next(T value);
};

#endif