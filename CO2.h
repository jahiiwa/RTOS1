#ifndef CO2_SENSOR_H
#define CO2_SENSOR_H

#include <Adafruit_ADS1X15.h>
#include <Wire.h>

class CO2Sensor {
private:
    Adafruit_ADS1115 ads;

public:
    CO2Sensor() {}

    void begin() {
        ads.begin();  // Inisialisasi ADS1115
    }

    // Fungsi untuk membaca nilai CO2 dari channel yang diberikan
    float readCO2(uint8_t channel) {
        int16_t adcValue = ads.readADC_SingleEnded(channel);
        if (adcValue < 0) {
            return NAN; // Return NaN jika gagal membaca sensor
        }
        return (adcValue * 3300.0 / 17687); // Konversi ke nilai yang sesuai
    }
};

extern CO2Sensor co2Sensor;

#endif
