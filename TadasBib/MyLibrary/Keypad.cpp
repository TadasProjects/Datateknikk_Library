#include "components.h"
#include <array>
#include <utility>
using std::array;
using std::pair;

array<pair<int,int>, 12> keypadLayout;
const char keys[] = {'1','2','3','4','5','6','7','8','9','*','0','#'};


void Keypad::startUp(int amount, int keyPins[]) {
    for (int i = 0; i < amount; i++) {
        pins[i] = keyPins[i];
        pinMode(pins[i], INPUT_PULLUP);
    }
}

// -- These 2 define the pins, and makes them INPUT_PULLUP using the code above. >:!
void Keypad::define(int p1,int p2,int p3,int p4,int p5,int p6,int p7) {
    int temp[] = {p1,p2,p3,p4,p5,p6,p7};
    startUp(7, temp);
}

int Keypad::getAmount() { return amount; }
int Keypad::getPin(int index) { 
    return pins[index]; 
}

void Keypad::keyMaping() {
    
    Serial.print("Mapping started, follow the instrusctions to map keypad correctly:");
    
    for (int i = 0; i < 12; i++) {
        char key = keys[i];
        Serial.print("Please press ");
        Serial.println(key);

        // ---- This bad boy, uhh, he let's the human brain catch up, by waiting for input. ----
        // --- (thease are indexes not actuall pin nr) ---
        bool keyScanned = false;

        while (!keyScanned) {           
            const int count = getAmount();
          
            for (int currentPin = 0; currentPin < count; currentPin++) {

                // ---- Changes the pins to the states i want (thease are indexes not actuall pin nr) ----
                for (int testingPin = 0; testingPin < count; testingPin++) {
                    int actuallPin = getPin(testingPin);
                
                    if (testingPin == currentPin) {
                        pinMode(actuallPin, OUTPUT);
                        digitalWrite(actuallPin, LOW);
                    } else {
                        pinMode(actuallPin, INPUT_PULLUP);
                    }
                }

                // ---- Where the actuall testing happens if pins are connected when button pressed in
                for (int testingPin = 0; testingPin < count; testingPin++) {
                    if (testingPin == currentPin) continue;
                    int readPin = getPin(testingPin);

                    if (digitalRead(readPin) == LOW) {
                        int drivePin = getPin(currentPin);

                        // The actaully mapping
                        keypadLayout[i] = {readPin, drivePin};

                        keyScanned = true;

                        while (digitalRead(readPin) == LOW) {
                            delay(5);
                        }
                        break;
                    }
                }

                if (keyScanned) break;
            }

            delay(5);
        }
    }
}
