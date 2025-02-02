#ifndef OLED_H
#define OLED_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definisi ukuran layar
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// ✅ Deklarasi objek OLED secara global
extern Adafruit_SSD1306 display;

extern const unsigned long interval;
extern unsigned long previousMillis;
extern int functionIndex;

// Deklarasi fungsi tanpa implementasi
void TCA9548A(uint8_t bus);
void oled_setup();
void OLED_print(String baris1, String baris2);
void OLED1_print(String baris1, String baris2);
int calculateX(String text);

#endif
