TaskHandle_t Display1_handler, Display2_handler, Display3_handler, SD_handler;

#include "C0.h"

void C0S() {
  xTaskCreatePinnedToCore(
    Display1,
    "Display1",
    2048,
    NULL,
    1,
    &Display1_handler,
    0);

  xTaskCreatePinnedToCore(
    Display2,
    "Display2",
    2048,
    NULL,
    1,
    &Display2_handler,
    0);

  xTaskCreatePinnedToCore(
    Display3,
    "Display3",
    2048,
    NULL,
    1,
    &Display3_handler,
    0);
  
    xTaskCreatePinnedToCore(
        SDTask,     // Fungsi Task
        "SDTask",   // Nama Task
        4096,       // Ukuran Stack
        NULL,       // Parameter
        1,          // Prioritas Task
        &SD_handler,       // Handle Task
        0           // Core 0 (ESP32 memiliki dua core: 0 & 1)
    );

  esp_task_wdt_add(Display1_handler);
  esp_task_wdt_add(Display2_handler);  
  esp_task_wdt_add(Display3_handler);
}