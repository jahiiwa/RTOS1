#ifndef MOF_SENSOR_H
#define MOF_SENSOR_H

#include <Wire.h>
#include <Adafruit_ADS1X15.h>

extern Adafruit_ADS1115 ads;  // Deklarasi ADS1115 (objek tunggal)
extern const float pga_range; // Gunakan `extern` agar tidak duplikat

void MOF_Setup();  // Setup ADC
void MOF_Loop();   // Fungsi loop sensor MOF

#endif
