#include <esp_task_wdt.h>

#include "DateTime.h"
#include "OLED.h"
#include "MHZ1.h"
#include "MHZ2.h"
#include "DHT22.h"
#include "CO2.h"
#include "PWM.h"
#include "Define_C0.h"
#include "Define_C1.h"

void setup() {
  esp_task_wdt_init(20, true);  // Set WDT timeout to 10 seconds

  Serial.begin(115200);

  MHZ1_Setup();
  MHZ2_Setup();
  PWM_Setup();
  DHT_Setup();

  RTCS();

  SemOLED1 = xSemaphoreCreateBinary();
  SemOLED2 = xSemaphoreCreateBinary();

  xSemaphoreGive(SemOLED1);

  OLED1_print("CO2", "PURIFIER");
  OLED2_print("LAB.", "MATERIAL");

  C0S();
  C1S();
}

void loop() {
}