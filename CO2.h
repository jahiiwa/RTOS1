#include <Adafruit_ADS1X15.h>
#include <Wire.h>

Adafruit_ADS1115 ads;

void CO2S() {
  ads.begin();  // Inisialisasi ADS1115
}

// Fungsi untuk membaca nilai CO2 dari channel yang diberikan
float CO2L(uint8_t channel) {
  int16_t adcValue = ads.readADC_SingleEnded(channel);
  if (adcValue < 0) {
    return NAN;  // Return NaN jika gagal membaca sensor
  }
  return (adcValue * 3300.0 / 17687);  // Konversi ke nilai yang sesuai
}
