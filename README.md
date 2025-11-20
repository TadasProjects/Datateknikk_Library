Keypad Library
Setup
#include "components.h"
Keypad Keypad;


void setup() {
    Serial.begin(115200);
    Keypad.define(2,3,4,5,6,7,8);
    Keypad.keyMaping();
}
Use
void loop() {
    char key = Keypad.getKey();
    if (key) {
        Serial.println(key);
    }
}
Commands

define(...) sets keypad pins

keyMaping() loads layout

getKey() returns pressed key
