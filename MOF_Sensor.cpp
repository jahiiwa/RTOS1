#include "MOF_Sensor.h"

Adafruit_ADS1115 ads;  // Inisialisasi objek ADS1115
const float pga_range = 6.144; // ±6.144V

void MOF_Setup() {
    Wire.begin(6, 7);
    ads.begin();
}
