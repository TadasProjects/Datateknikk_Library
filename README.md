# Keypad Library

<div align="center"><strong>Simple keypad setup and usage</strong></div>

## Setup

```cpp
#include "components.h"
Keypad Keypad;

void setup() {
    Keypad.define(2,3,4,5,6,7,8); // the numbers are pins going from keypad too the arduino these do not need to be sorted
    Keypad.keyMaping(); // this maps the keypad, no other code will run whilest it's mapping, follow the instructions in serial monitor
}
```

## Use

```cpp
void loop() {
    char key = Keypad.getKey(); // get's the key this code outputs 0 so you'll get nothing outputed but the chat might still be spammed
    if (key) { // that's why you need this to check if there is something in there
        Serial.println(key);
    }
}
```

## Commands

**define(...)** sets the pins connected to the keypad  
**keyMaping()** starts the mapping process and guides you in Serial Monitor  
**getKey()** returns the pressed key or 0 when nothing is pressed  

