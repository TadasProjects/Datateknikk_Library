#include "components.h"

Adafruit_BME280 bme;
SparkFun_ENS160 ens;

void bmeStartup() {
    // ---- Creates boolean
    bool ok = false;

    ok = bme.begin(0x76);      // -- If it works on 0x76, chooses 0x76 as the i2c port
    if (!ok) {
        ok = bme.begin(0x77);  // -- If the first does not works, chooses 0x77 as the i2c port
    }


    // ---- Tries to see if it's connected
    if (!ok) {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
        while (1) {
            delay(10);
        }
    }
}

void ensStartup() {

    // ---- Tries to see if it's connected
    if (!ens.begin()) {
        Serial.println(F("Could not find a valid ENS160 sensor, check wiring!"));
        while (1) {
            delay(10);
        }
    }

    if (ens.setOperatingMode(SFE_ENS160_RESET)) {
        Serial.println("ENS ready");
    }

    delay(100);

    // -- Compensatest using the BME sensor if it's present.
    if (bme.sensorID()) {
        float t = bme.readTemperature();
        float h = bme.readHumidity();

        ens.setTempCompensationCelsius(t);
        ens.setRHCompensationFloat(h);
    }

    ens.setOperatingMode(SFE_ENS160_STANDARD);
}
