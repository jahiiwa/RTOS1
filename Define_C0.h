TaskHandle_t WiFi_setup_handler, Timer_Kirim_handler, Display1_handler, Display2_handler;

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

  esp_task_wdt_add(WiFi_setup_handler);
  esp_task_wdt_add(Timer_Kirim_handler);
  esp_task_wdt_add(Display1_handler);
  esp_task_wdt_add(Display2_handler);
}