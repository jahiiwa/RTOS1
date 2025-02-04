#include <esp_task_wdt.h>

#include "MHZ1.h"
#include "MHZ2.h"
#include "FuzzyKipas.h"
#include "DHT22.h"
#include "CO2.h"
#include "PWM.h"
#include "SDCard.h"
#include "OLED.h"
#include "Define_C0.h"
#include "Define_C1.h"

void setup() {
  esp_task_wdt_init(20, true);  // Set WDT timeout to 10 seconds

  Serial.begin(115200);

  SD_Setup();
  MHZ1_Setup();
  MHZ2_Setup();
  Kipas_setup();
  PWM_Setup();
  DHT_Setup();
  OLED1_print("CO2", "PURIFIER");
  OLED2_print("LAB.", "MATERIAL");
  vTaskDelay(2000 / portTICK_PERIOD_MS);

  SemOLED1 = xSemaphoreCreateBinary();
  SemOLED2 = xSemaphoreCreateBinary();
  SemOLED3 = xSemaphoreCreateBinary();

  xSemaphoreGive(SemOLED1);

  C0S();
  C1S();
}

void loop() {
}