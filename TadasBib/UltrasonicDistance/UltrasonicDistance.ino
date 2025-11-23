#include <components.h>

DelayMillis blink;        // simple repeating
DelayMillis sensor;       // simple repeating
DelayMillis loopBreaker;  // used inside for-loop

void setup() {
    Serial.begin(115200);
}

void loop() {

    // ---------- 1: Repeating timer every 200ms ----------
    if (blink.delayMillis(200)) {
        Serial.println("Blink event");
    }

    // ---------- 2: Repeating timer every 1000ms ----------
    if (sensor.delayMillis(1000)) {
        Serial.println("Sensor read");
    }


    // ---------- 3: Timer-inside-for-loop ----------
    for (int i = 0; i < 500; i++) {

        Serial.print("i = ");
        Serial.println(i);

        // If loopBreaker reaches 300ms, exit the for loop early
        if (loopBreaker.delayMillis(300)) {
            Serial.println("300ms passed, breaking loop");
            break;   // you could also use 'return'
        }

        // Do slow work here
        delay(5); // simulate some work (you can remove this)
    }

    // rest of your code continues normally...
}
