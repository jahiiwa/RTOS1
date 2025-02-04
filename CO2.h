#include <Adafruit_ADS1X15.h>
#include <Wire.h>

bool ADS_status;

Adafruit_ADS1115 ads;

void CO2S() {
  ADS_status = ads.begin();  // Inisialisasi ADS1115
}

// Fungsi untuk membaca nilai CO2 dari channel yang diberikan
float CO2L(uint8_t channel) {
  if (ADS_status) {
    int16_t adcValue = ads.readADC_SingleEnded(channel);
    if (adcValue < 0) {
      return NAN;  // Return NaN jika gagal membaca sensor
    }
    return (adcValue * 3300.0);  // Konversi ke nilai yang sesuai
  } else return NAN;
}
