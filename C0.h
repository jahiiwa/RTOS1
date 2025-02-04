#include "esp_task_wdt.h"
SemaphoreHandle_t SemOLED1, SemOLED2, SemOLED3;

void Display1(void *pvParameters) {
  while (1) {
    xSemaphoreTake(SemOLED1, portMAX_DELAY);
    //Serial.println("Display1");
    OLED1_print("MHZ Inlet", String(mhz_inlet) + " ppm");
    OLED2_print("MHZ Outlet", String(mhz_outlet) + " ppm");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
    xSemaphoreGive(SemOLED2);
    esp_task_wdt_reset();
  }
}

void Display2(void *pvParameters) {
  while (1) {
    xSemaphoreTake(SemOLED2, portMAX_DELAY);
    //Serial.println("Display2");
    OLED1_print("Suhu Udara", String(t) + " C");
    OLED2_print("Kelembapan", String(h) + " %");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
    xSemaphoreGive(SemOLED3);
    esp_task_wdt_reset();
  }
}

void Display3(void *pvParameters) {
  while (1) {
    xSemaphoreTake(SemOLED3, portMAX_DELAY);
    //Serial.println("Display3");
    OLED1_print("MOF inlet", String(mof_inlet) + " ppm");
    OLED2_print("MOF outlet", String(mof_outlet) + " ppm");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
    xSemaphoreGive(SemOLED1);
    esp_task_wdt_reset();
  }
}

void SDTask(void *pvParameters) {
  while (1) {
    writeDataToSD();
    vTaskDelay(5000 / portTICK_PERIOD_MS);  // Tunggu 5 detik sebelum menulis data lagi
    esp_task_wdt_reset();
  }
}