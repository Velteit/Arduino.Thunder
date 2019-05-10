#ifndef RELAY_H
#define RELAY_H

#include "collection.h"

class Relay {
    private:
        uint8_t _pin;
        bool _opened;

    public:
        Relay(uint8_t pin, bool state);
        bool open();
        bool close();
};

#endif