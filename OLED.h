#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definisi ukuran layar
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const unsigned long interval = 2000;  // Interval 2 detik
unsigned long previousMillis = 0;
int functionIndex = 0;

int calculateX(String text) {
  int textWidth = text.length() * 12;     // 12 piksel per karakter pada setTextSize(2)
  return (SCREEN_WIDTH - textWidth) / 2;  // Hitung posisi tengah
}

// Pilih I2C BUS
void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);  // Alamat TCA9548A
  Wire.write(1 << bus);          // Kirim byte untuk memilih bus
  Wire.endTransmission();
}

void OLED1_print(String baris1, String baris2) {
  TCA9548A(6);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(calculateX(baris1), 20);
  display.print(baris1);
  display.setCursor(calculateX(baris2), 44);
  display.print(baris2);
  display.display();
}

void OLED2_print(String baris1, String baris2) {
  TCA9548A(7);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(calculateX(baris1), 20);
  display.print(baris1);
  display.setCursor(calculateX(baris2), 44);
  display.print(baris2);
  display.display();
}
