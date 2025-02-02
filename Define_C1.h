#include "C1.h"

void C1S() {
  xTaskCreatePinnedToCore(
    MHZ1_Task,
    "MHZ1_Task",
    4096,
    NULL,
    1,
    NULL,
    1
  );

  xTaskCreatePinnedToCore(
    MHZ2_Task,
    "MHZ2_Task",
    4096,
    NULL,
    1,
    NULL,
    1
  );

  xTaskCreatePinnedToCore(
    MOF1_Task,
    "MOF1_Task",
    4096,
    NULL,
    1,
    NULL,
    1
  );

  xTaskCreatePinnedToCore(
    MOF2_Task,
    "MOF2_Task",
    4096,
    NULL,
    1,
    NULL,
    1
  );

  xTaskCreatePinnedToCore(
    DHT_Task,
    "DHT_Task",
    4096,
    NULL,
    1,
    NULL,
    1
  );
}

void C2S() {
  xTaskCreatePinnedToCore(
    Fuzzy_Task,   // Fungsi task
    "Fuzzy_Task", // Nama task
    4096,       // Ukuran stack
    NULL,        // Parameter untuk task
    1,           // Prioritas task
    NULL,        // Handle task
    1            // Jalankan di core 1
  );
}
