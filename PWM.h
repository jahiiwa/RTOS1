#include "Kontrol_PWM.h"

double mof_inlet, mof_outlet;

void PWM_Setup() {
  // Setup PWM
  setupPWM();

  // Initialize CO2 sensors
  CO2S();

  // Set initial duty cycle to 12 for both PWM pins
  setPWM(PWM_PIN1, 12);
  setPWM(PWM_PIN2, 12);

  Serial.println("Masukkan nilai duty cycle untuk PWM1 dan PWM2 (format: DC1,DC2):");
}

void PWM_Loop() {
  static uint8_t dutyCycle1 = 12;
  static uint8_t dutyCycle2 = 12;

  // Check for input from Serial Monitor
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  // Remove whitespace or extra characters

    // Parse input as two integers separated by a comma
    int commaIndex = input.indexOf(',');
    if (commaIndex != -1) {
      String duty1Str = input.substring(0, commaIndex);
      String duty2Str = input.substring(commaIndex + 1);

      int newDutyCycle1 = duty1Str.toInt();
      int newDutyCycle2 = duty2Str.toInt();

      // Validate ranges for both duty cycles
      if (newDutyCycle1 >= 0 && newDutyCycle1 <= 100 && newDutyCycle2 >= 0 && newDutyCycle2 <= 100) {

        dutyCycle1 = newDutyCycle1;
        dutyCycle2 = newDutyCycle2;

        // Set PWM for both pins
        setPWM(PWM_PIN1, dutyCycle1);
        setPWM(PWM_PIN2, dutyCycle2);

        Serial.print("Duty Cycle PWM1 diatur ke: ");
        Serial.println(dutyCycle1);
        Serial.print("Duty Cycle PWM2 diatur ke: ");
        Serial.println(dutyCycle2);
      } else {
        Serial.println("Masukkan nilai duty cycle antara 0-100 untuk kedua pin.");
      }
    } else {
      Serial.println("Format salah. Gunakan format: DC1,DC2 (contoh: 50,75)");
    }
  }
}
