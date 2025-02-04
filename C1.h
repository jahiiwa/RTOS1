void MHZ1_Task(void *pvParameters) {
  while (1) {
    MHZ1_Loop();
    Serial.println(F("MHZ1_Task running"));

    vTaskDelay(60000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void MHZ2_Task(void *pvParameters) {
  while (1) {
    MHZ2_Loop();
    Serial.println(F("MHZ2_Task running"));

    vTaskDelay(60000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void MOF_Task(void *pvParameters) {
  while (1) {
    mof_inlet = CO2L(0);   // Membaca dari A0
    mof_outlet = CO2L(3);  // Membaca dari A3
    
    Serial.print("CO2 Inlet: ");
    Serial.print(mof_inlet);
    Serial.println(" ppm");
    Serial.print("CO2 Outlet: ");
    Serial.print(mof_outlet);
    Serial.println(" ppm");

    vTaskDelay(60000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();
  }
}

// Task untuk mengontrol PWM
void PWM_Task(void *pvParameters) {
  while (1) {
    PWM_Loop();
    Serial.println(F("PWM_Task running"));

    vTaskDelay(60000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}



void DHT_Task(void *pvParameters) {
  while (1) {
    DHT_Loop();
    Serial.println(F("DHT_Task running"));

    vTaskDelay(60000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();  // Reset WDT setelah task ini selesai looping
  }
}

void Fuzzy_Task(void *pvParameters) {
  while (1) {
    Kipas_Loop();
    // Tampilkan nilai input dan output ke Serial Monitor
    Serial.println(F("Fuzzy_Task running"));
    // Delay 5 detik menggunakan RTOS
    vTaskDelay(60000 / portTICK_PERIOD_MS);
    esp_task_wdt_reset();
  }
}
