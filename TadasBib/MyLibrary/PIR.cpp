#include "components.h"
#include <Arduino.h>

void PIR::define(int pirPin) {
    pinNumber = pirPin;
    pinMode(pinNumber, INPUT_PULLUP);
}

int PIR::motionDetected() {
    int val = digitalRead(pinNumber);

    if (val == LOW) {
        // Motion just started
        if (state == LOW) {
            state = HIGH;
            return 0;   // motion started
        }
    } else {
        // Motion just stopped
        if (state == HIGH) {
            state = LOW;
            return 1;   // motion stopped
        }
    }

    return -1;  // no change
}
