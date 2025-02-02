#include "FuzzyKipas.h"
SemaphoreHandle_t sensorSemaphore;

// Task untuk membaca sensor MHZ1
void MHZ1_Task(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(sensorSemaphore, portMAX_DELAY)) {
            MHZ1_Loop();
            Serial.println(F("MHZ1_Task running"));
            xSemaphoreGive(sensorSemaphore);
        }
        
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        esp_task_wdt_reset();
    }
}

// Task untuk membaca sensor MHZ2
void MHZ2_Task(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(sensorSemaphore, portMAX_DELAY)) {
            MHZ2_Loop();
            Serial.println(F("MHZ2_Task running"));
            xSemaphoreGive(sensorSemaphore);
        }

        vTaskDelay(5000 / portTICK_PERIOD_MS);
        esp_task_wdt_reset();
    }
}

// Task untuk membaca sensor MOF1
void MOF1_Task(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(sensorSemaphore, portMAX_DELAY)) {
            MOF1_Loop();
            Serial.println(F("MOF1_Task running"));
            xSemaphoreGive(sensorSemaphore);
        }

        vTaskDelay(5000 / portTICK_PERIOD_MS);
        esp_task_wdt_reset();
    }
}

// Task untuk membaca sensor MOF2
void MOF2_Task(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(sensorSemaphore, portMAX_DELAY)) {
            MOF2_Loop();
            Serial.println(F("MOF2_Task running"));
            xSemaphoreGive(sensorSemaphore);
        }

        vTaskDelay(5000 / portTICK_PERIOD_MS);
        esp_task_wdt_reset();
    }
}

// Task untuk membaca sensor DHT
void DHT_Task(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(sensorSemaphore, portMAX_DELAY)) {
            DHT_Loop();
            Serial.println(F("DHT_Task running"));
            xSemaphoreGive(sensorSemaphore);
        }

        vTaskDelay(5000 / portTICK_PERIOD_MS);
        esp_task_wdt_reset();
    }
}

// Task untuk kontrol fuzzy kipas
void Fuzzy_Task(void *pvParameters) {
    while (1) {
        fuzzy->setInput(1, mhz_inlet);
        fuzzy->fuzzify();
        float output = fuzzy->defuzzify(1);

        if (output < 0) output = 0;
        if (output > 255) output = 255;

        ledcWrite(33, output);

        if (output >= 0 && output <= 125) {
            digitalWrite(ledHijau, HIGH);
            digitalWrite(ledKuning, LOW);
            digitalWrite(ledMerah, LOW);
        } else if (output > 125 && output <= 210) {
            digitalWrite(ledHijau, LOW);
            digitalWrite(ledKuning, HIGH);
            digitalWrite(ledMerah, LOW);
        } else {
            digitalWrite(ledHijau, LOW);
            digitalWrite(ledKuning, LOW);
            digitalWrite(ledMerah, HIGH);
        }

        Serial.println(F("Fuzzy_Task running"));
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
