#include "components.h"
#include <Wire.h>

const uint8_t OLED_ADDR = 0x3C;

#ifdef OLED_BACKEND_TEXT

SSD1306AsciiWire display;

void oledStartup() {
    Wire.begin();
    display.begin(&Adafruit128x64, OLED_ADDR);
    display.clear();
    display.setFont(System5x7);
    display.setCursor(0, 0);
}

#elif defined(OLED_BACKEND_ADAFRUIT)

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void oledStartup() {
    Wire.begin();
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        while (true) { } 
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.display();
}

#endif