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
#include "Define_C0.h"
#include "Define_C1.h"

void setup() {
  Serial.begin(115200);

  MHZ1_Setup();
  MHZ2_Setup();
  DHT_Setup();

  C0S();
  C1S();
  C2S();
}

void loop() {
}