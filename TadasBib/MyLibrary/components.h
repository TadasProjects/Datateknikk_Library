#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <Arduino.h>

// Choose backend HERE (one place)
#define OLED_BACKEND_TEXT
// or:
// #define OLED_BACKEND_ADAFRUIT

// choose backend
#ifdef OLED_BACKEND_TEXT
    #include <SSD1306Ascii.h>
    #include <SSD1306AsciiWire.h>
    extern SSD1306AsciiWire display;
    void oledStartup();
#elif defined(OLED_BACKEND_ADAFRUIT)
    #include <Adafruit_GFX.h>
    #include <Adafruit_SSD1306.h>
    extern Adafruit_SSD1306 display;
    void oledStartup();
#endif

class Keypad {
private:
    int amount;
    int pins[7];

    // ---- Code to initialize pins as ---- Used in corelation with define ---- 
    void startUp(int amount, int keyPins[]);
public:

    void define(int p1,int p2,int p3,int p4,int p5,int p6,int p7);

    int getAmount();
    int getPin(int index);

    void keyMaping();
    char getKey();
};

// Frontend (empty logic for now)
class Frontend {
private:
public:
};

#endif