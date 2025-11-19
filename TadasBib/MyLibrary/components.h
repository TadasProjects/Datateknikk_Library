#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <Arduino.h>

class Keypad {
private:
    int amount;
    int pins[8];

    // ---- Code to initialize pins as ---- Used in corelation with define ---- 
    void startUp(int amount, int keyPins[]);
public:

    void define(int p1,int p2,int p3,int p4,int p5,int p6,int p7);
    void define(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8);

    int getAmount();
    int* getPins();
    int getPin(int index);

    void keyMaping();
};

// Frontend (empty logic for now)
class Frontend {
private:
    Keypad &kp;
public:
    Frontend(Keypad &ref);
    void init();
    void update();
};

#endif
