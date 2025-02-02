#include "Kirim.h"
#include "Wifi.h"
#include <Wire.h>
#include <RTClib.h>        // Library untuk DS3231

// Task untuk sinkronisasi RTC dengan RTOS
void RTCS(void *pvParameters) {
  while (1) {
    if (!rtc.begin()) {
      Serial.println(F("RTC DS3231 tidak terdeteksi!"));
      while (1); // Berhenti jika RTC tidak ditemukan
    }

    if (rtc.lostPower()) {
      Serial.println(F("RTC kehilangan daya, mengatur ulang waktu!"));
      // Set waktu awal jika RTC kehilangan daya (contoh: 1 Januari 2025, pukul 00:00:00)
      rtc.adjust(DateTime(2025, 1, 1, 0, 0, 0));
    }

    // Cetak waktu sekarang setiap 1 detik
    //Serial.println(F("Waktu sekarang: " + get_date_time(0)));
    Serial.println(F("RTC_Task running"));
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 detik untuk pembaruan waktu
  }
}

// Task untuk koneksi WiFi
void WiFi_setup(void *pvParameters) {
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

  vTaskDelete(NULL);
}



void Timer_Kirim(void *pvParameters) {
  while (1) {
    if (WiFi.status() == WL_CONNECTED) {
      DateTime now = rtc.now(); // Ambil waktu dari DS3231

      if (now.year() >= 2024 && now.year() <= 2030) {
        if (now.second() % 5 == 0) {
            Kirim_raw();
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
      }
      Serial.println(F("TimerKirim_Task running"));
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }
  }
}
