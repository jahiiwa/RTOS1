#include "Kirim.h"
#include "Wifi.h"
#include <Wire.h>
#include <RTClib.h>  // Library untuk DS3231

// Task untuk koneksi WiFi
void WiFi_setup(void *pvParameters) {
  while (1) {
    if (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid.c_str(), pass.c_str());  // Tambahkan .c_str() agar sesuai tipe data

      while (WiFi.status() != WL_CONNECTED) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        Serial.print(".");
      }

      Serial.println("\nConnected to WiFi");

      // **Pastikan konfigurasi Firebase sudah benar**
      config.api_key = API_KEY;
      config.database_url = DATABASE_URL;

      Firebase.begin(&config, &auth);
      Firebase.reconnectWiFi(true);

      Serial.println("Firebase Initialized");
    }

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();
  }
}



void Timer_Kirim(void *pvParameters) {
  while (1) {
    if (WiFi.status() == WL_CONNECTED) {
      DateTime now = rtc.now();  // Ambil waktu dari DS3231

      if (now.year() >= 2024 && now.year() <= 2030) {
        if (now.second() % 5 == 0) {
          Kirim_raw();
          vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
      }
    }
    Serial.println(F("TimerKirim_Task running"));
    vTaskDelay(500 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}
