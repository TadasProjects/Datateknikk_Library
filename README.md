# Keypad Library

<div align="center"><strong>Simple keypad setup and usage</strong></div>

## Setup

```cpp
#include "components.h"
Keypad Keypad;

void setup() {
    Serial.begin(115200);
    Keypad.define(2,3,4,5,6,7,8);
    Keypad.keyMaping();
}
```

## Use

```cpp
void loop() {
    char key = Keypad.getKey();
    if (key) {
        Serial.println(key);
    }
}
```

## Commands

<div align="center"><strong>define(...)</strong> sets keypad pins</div>
<div align="center"><strong>keyMaping()</strong> loads layout</div>
<div align="center"><strong>getKey()</strong> returns pressed key</div>
