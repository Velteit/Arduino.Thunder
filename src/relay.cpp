#include <Arduino.h>
#include "relay.h"
#include "collection.h"


bool Relay::open() {
    if (!_opened) {
        _opened = true;

        digitalWrite(_pin, HIGH);
        delay(100);

        return true;
    }
    
    return false;
};

bool Relay::close() {
    if (_opened) {
        _opened = false;

        digitalWrite(_pin, LOW);
        delay(100);

        return true;
    }
    
    return false;
};

Relay::Relay(uint8_t pin, bool state) {
    _pin = pin;
    state = state;
}
