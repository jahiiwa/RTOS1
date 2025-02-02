#include "OLED.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const unsigned long interval = 2000;  // Interval 2 detik
unsigned long previousMillis = 0;
int functionIndex = 0;

int calculateX(String text) {
    int textWidth = text.length() * 12;  // 12 piksel per karakter pada setTextSize(2)
    return (SCREEN_WIDTH - textWidth) / 2;  // Hitung posisi tengah
}

// Pilih I2C BUS
void TCA9548A(uint8_t bus) {
    Wire.beginTransmission(0x70);  // Alamat TCA9548A
    Wire.write(1 << bus);  // Kirim byte untuk memilih bus
    Wire.endTransmission();
}

void oled_setup() {
    Wire.begin();

    // Inisialisasi OLED pada bus 6
    TCA9548A(6);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 gagal dialokasikan"));
        for (;;);
    }
    display.clearDisplay();

    // Inisialisasi OLED pada bus 7
    TCA9548A(7);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 gagal dialokasikan"));
        for (;;);
    }
    display.clearDisplay();
}

void OLED_print(String baris1, String baris2) {
    TCA9548A(6);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(calculateX(baris1), 20);
    display.print(baris1);
    display.setCursor(calculateX(baris2), 44);
    display.print(baris2);
    display.display();
}

void OLED1_print(String baris1, String baris2) {
    TCA9548A(7);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(calculateX(baris1), 20);
    display.print(baris1);
    display.setCursor(calculateX(baris2), 44);
    display.print(baris2);
    display.display();
}
