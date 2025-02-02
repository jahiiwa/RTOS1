TaskHandle_t MHZ1_Task_handler, MHZ2_Task_handler, MOF_Task_handler, PWM_Task_handler, DHT_Task_handler, Fuzzy_Task_handler;

#include "C1.h"

void C1S() {
  xTaskCreatePinnedToCore(
    MHZ1_Task,
    "MHZ1_Task",
    4096,
    NULL,
    1,
    &MHZ1_Task_handler,
    1);

  xTaskCreatePinnedToCore(
    MHZ2_Task,
    "MHZ2_Task",
    4096,
    NULL,
    1,
    &MHZ2_Task_handler,
    1);

  xTaskCreatePinnedToCore(
    MOF_Task,
    "MOF_Task",
    4096,
    NULL,
    1,
    &MOF_Task_handler,
    1);

  xTaskCreatePinnedToCore(
    PWM_Task,
    "PWM_Task",
    4096,
    NULL,
    1,
    &PWM_Task_handler,
    1);


  xTaskCreatePinnedToCore(
    DHT_Task,
    "DHT_Task",
    4096,
    NULL,
    1,
    &DHT_Task_handler,
    1);

  xTaskCreatePinnedToCore(
    Fuzzy_Task,           // Fungsi task
    "Fuzzy_Task",         // Nama task
    4096,                 // Ukuran stack
    NULL,                 // Parameter untuk task
    1,                    // Prioritas task
    &Fuzzy_Task_handler,  // Handle task
    1                     // Jalankan di core 1
  );

  esp_task_wdt_add(MHZ1_Task_handler);
  esp_task_wdt_add(MHZ2_Task_handler);
  esp_task_wdt_add(MOF_Task_handler);
  esp_task_wdt_add(PWM_Task_handler);
  esp_task_wdt_add(DHT_Task_handler);
  esp_task_wdt_add(Fuzzy_Task_handler);
}