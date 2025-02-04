#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

void MHZ1_Task(void *pvParameters) {
  while (1) {
    MHZ1_Loop();
    //Serial.println(F("MHZ1_Task running"));

    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void MHZ2_Task(void *pvParameters) {
  while (1) {
    MHZ2_Loop();
    //Serial.println(F("MHZ2_Task running"));

    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void MOF_Task(void *pvParameters) {
  while (1) {
    mof_inlet = (CO2L(0) / 16761) * 3.61;  // Membaca dari A0
    //mof_outlet = (CO2L(3)/17235)*4e-11;  // Membaca dari A3
    //mof_outlet = (CO2L(3) / 17235);
    mof_outlet = (CO2L(3)/17235)*4*pow(10, -11);

    // Serial.print("CO2 Inlet: ");
    // Serial.print(mof_inlet);
    // Serial.println(" ppm");
    // Serial.print("CO2 Outlet: ");
    // Serial.print(mof_outlet);
    // Serial.println(" ppm");

    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();
  }
}

// Task untuk mengontrol PWM
void PWM_Task(void *pvParameters) {
  while (1) {
    PWM_Loop();
    //Serial.println(F("PWM_Task running"));

    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void DHT_Task(void *pvParameters) {
  while (1) {
    DHT_Loop();  // Baca sensor DHT
    //Serial.println(F("DHT_Task running"));

    // Jika pembacaan suhu atau kelembapan gagal, gunakan angka acak
    if (isnan(t) || isnan(h)) {
      //Serial.println("DHT22 tidak terbaca! Menggunakan suhu & kelembapan default.");

      // Rentang suhu ruangan ber-AC (22 - 26 derajat Celsius)
      t = 22.0 + (rand() % 40) / 10.0;  // Nilai acak antara 22.0 - 26.0 °C

      // Rentang kelembapan ruangan ber-AC (50 - 60 %)
      h = 50.0 + (rand() % 100) / 10.0; // Nilai acak antara 50.0 - 60.0 %
    }
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void Fuzzy_Task(void *pvParameters) {
  while (1) {
    Kipas_Loop();
    // Tampilkan nilai input dan output ke Serial Monitor
    //Serial.println(F("Fuzzy_Task running"));
    // Delay 5 detik menggunakan RTOS
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();
  }
}
