# Components Library

<div align="center"><strong>Keypad and OLED usage</strong></div>

## Keypad Setup

```cpp
#include "components.h"
Keypad Keypad;

void setup() {
    Keypad.define(2,3,4,5,6,7,8); // the numbers are pins going from keypad too the arduino these do not need to be sorted
    Keypad.keyMaping(); // this maps the keypad, no other code will run whilest it's mapping, follow the instructions in serial monitor
}
```

## Keypad Use

```cpp
void loop() {
    char key = Keypad.getKey(); // gets the key, this code outputs 0 so nothing will print unless something is pressed
    if (key) { // prevents spam from empty reads
        Serial.println(key);
    }
}
```

## Keypad Commands

**define(...)** sets the pins connected to the keypad  
**keyMaping()** starts the mapping process and guides you in Serial Monitor  
**getKey()** returns the pressed key or 0 when nothing is pressed  

---

## OLED Setup

Choose which backend you want to use. Only one can be active.

```cpp
// Choose backend HERE
#define OLED_BACKEND_TEXT
// or
// #define OLED_BACKEND_ADAFRUIT
```

## OLED Use

Call `oledStartup()` once in `setup()` to initialize and prepare the display.

For all printing and drawing commands, use the documentation for the backend you selected.

### Commands for SSD1306Ascii  
Official documentation:  
https://github.com/greiman/SSD1306Ascii#api-reference

### Commands for Adafruit SSD1306 and GFX  
Adafruit SSD1306 API:  
https://github.com/adafruit/Adafruit_SSD1306  

Adafruit GFX API (text, shapes, cursor control):  
https://github.com/adafruit/Adafruit-GFX-Library#graphics-primitives-and-text
