#include "FuzzyKipas.h"

void MHZ1_Task(void *pvParameters) {
  while (1) {
    MHZ1_Loop();
    Serial.println(F("MHZ1_Task running"));
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void MHZ2_Task(void *pvParameters) {
  while (1) {
    MHZ2_Loop();
    Serial.println(F("MHZ2_Task running"));
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void DHT_Task(void *pvParameters) {
  while (1) {
    DHT_Loop();
    Serial.println(F("DHT_Task running"));
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void Fuzzy_Task(void *pvParameters) {
  while (1) {

    fuzzy->setInput(1, mhz_inlet);
    fuzzy->fuzzify();

    // Hitung output fuzzy logic
    float output = fuzzy->defuzzify(1);

    // Batasi output PWM ke rentang yang valid
    if (output < 0) output = 0;
    if (output > 255) output = 255;

    // Tulis output ke pin PWM
    ledcWrite(33, output);

    // Kontrol LED berdasarkan kategori output kipas
    if (output >= 0 && output <= 125) { // Kipas pelan
      digitalWrite(ledHijau, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledMerah, LOW);
    } else if (output > 125 && output <= 210) { // Kipas standar
      digitalWrite(ledHijau, LOW);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledMerah, LOW);
    } else if (output > 210 && output <= 255) { // Kipas cepat
      digitalWrite(ledHijau, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledMerah, HIGH);
    }

    // Tampilkan nilai input dan output ke Serial Monitor
    Serial.println(F("Fuzzy_Task running"));

    // Delay 5 detik menggunakan RTOS
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();
  }
}
