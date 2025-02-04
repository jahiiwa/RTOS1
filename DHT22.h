float t, h;

#include <DHT.h>

#define DHT_TYPE DHT22
#define DHT_PIN 27

DHT dht(DHT_PIN, DHT_TYPE);

void DHT_Setup() {
  dht.begin();
}

void DHT_Loop() {
  t = dht.readTemperature();
  h = dht.readHumidity();
}