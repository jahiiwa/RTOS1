#include "C0.h"

void C0S() {
  xTaskCreatePinnedToCore(
    WiFi_setup,
    "WiFi_setup",
    3072,
    NULL,      
    1,
    NULL,
    0
  );

  xTaskCreatePinnedToCore(
    RTCS,
    "RTCS",
    1024,
    NULL,
    1,
    NULL,
    0
  );

  xTaskCreatePinnedToCore(
    Timer_Kirim,
    "Timer_Kirim",
    4096,
    NULL,
    1,
    NULL,
    0
  );
}