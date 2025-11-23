#include "components.h" 

bool DelayMillis::delayMillis(unsigned long ms) {
    unsigned long now = millis();

    if (now - lastTime >= ms) {
        lastTime = now;
        return true;
    }

    return false;
}
