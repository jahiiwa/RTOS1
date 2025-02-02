#include <esp_task_wdt.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_ADS1X15.h>
#include <Wire.h>

#include "DateTime.h"
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
  
  co2Sensor.begin();
  MHZ1_Setup();
  MHZ2_Setup();
  PWM_Setup();
  DHT_Setup();

  RTCS();

  C0S();
  C1S();

  while (1) { // Biarkan task berjalan
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void loop() {
}