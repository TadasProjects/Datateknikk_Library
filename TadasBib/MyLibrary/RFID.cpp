#include "components.h"

extern MFRC522 rfid;  // the real reader is defined in the .ino

// - Quite similart to a python dictionary
struct Card {
    bool used;
    byte uid[7];
    byte len;
    byte user;
};

// - Makes it so you can have max 10 what i will call dictionaries.
static const byte MAX_CARDS = 10;

// - Creates an array of "dictionaries" 
Card cards[MAX_CARDS];

bool RFID::isCardPresentReadIt() {
    // - Uses the liberary of MFRC522 to see if the card is present
    // if it was read succesfully
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
        return true;
    }
    return false;
}

void RFID::findUID() {
    Serial.print("UID: ");
    // ---- Go thrue the scanned uid bytes
    for (byte i = 0; i < rfid.uid.size; i++) {
        // ---- If byte less than 0x10 then it adds a 0 at the end
        if (rfid.uid.uidByte[i] < 0x10) Serial.print('0');
        // ---- Print the bytes hex decimal
        Serial.print(rfid.uid.uidByte[i], HEX);
        // ---- If not last prints :
        if (i < rfid.uid.size - 1) Serial.print(':');
    }
    Serial.println();
}

bool RFID::doesExist(const byte *uid, byte len) {


    // ---- Goes thrue the whole array
    for (int i = 0; i < MAX_CARDS; i++) {
        if (!cards[i].used) continue;
        if (cards[i].len != len) continue;

        // ---- Compares all UID to find a matching one if it exist
        bool match = true;
        for (byte j = 0; j < len; j++) {
            if (cards[i].uid[j] != uid[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

bool RFID::addCard(const byte *uid, byte len, byte user) {
    if (doesExist(uid, len)) return false;

    for (int i = 0; i < MAX_CARDS; i++) {
        // --- Finds unused card slot
        if (!cards[i].used) {
            cards[i].used = true;
            cards[i].len  = len;

            for (byte j = 0; j < len; j++) {
                cards[i].uid[j] = uid[j];
            }

            cards[i].user = user;

            // ---- Returns true if card was successfully added
            return true;
        }
    }
    return false;
}

bool RFID::removeCard(const byte *uid, byte len) {
    if (!doesExist(uid, len)) return false;

    // ---- Goes thure the whole list
    for (int i = 0; i < MAX_CARDS; i++) {
        if (!cards[i].used) continue;
        if (cards[i].len != len) continue;

        // ---- Checks if the bites match this goes thrue all bytes
        // so if any don't match it goes to false
        bool match = true;
        for (byte j = 0; j < len; j++) {
            if (cards[i].uid[j] != uid[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            cards[i].used = false;
            return true;
        }

        // --- The thing below only checked if any of the bits match.
        // not if all of the bits matched, the more you know.

//        if(cards[i].used){
//            for (byte j = 0; j < len; j++) {
//                if (cards[i].uid[j] == uid[j]) {
//                    cards[i].used = false;
//                    return true;
//                }
//            }
//        }
    }

    return false;
}

bool RFID::removeCard(byte user) {

    // ---- Goes thrue the whole array
    for (int i = 0; i < MAX_CARDS; i++) {
        if (!cards[i].used) continue;

        if (cards[i].user == user) {
            cards[i].used = false;
            return true;
        }
    }
    return false;
}
