TaskHandle_t WiFi_setup_handler, Timer_Kirim_handler;

#include "C0.h"

void C0S() {
  xTaskCreatePinnedToCore(
    WiFi_setup,
    "WiFi_setup",
    3072,
    NULL,
    1,
    &WiFi_setup_handler,
    0);

  xTaskCreatePinnedToCore(
    Timer_Kirim,
    "Timer_Kirim",
    4096,
    NULL,
    1,
    &Timer_Kirim_handler,
    0);

  esp_task_wdt_add(WiFi_setup_handler);
  esp_task_wdt_add(Timer_Kirim_handler);
}