// Define PWM pins for ESP32
#define PWM_PIN1 16
#define PWM_PIN2 17

void setupPWM() {
  // Inisialisasi saluran PWM
  ledcSetup(0, 5000, 8);  // Channel 0, 5kHz, 8-bit
  ledcSetup(1, 5000, 8);  // Channel 1, 5kHz, 8-bit

  // Hubungkan pin PWM ke saluran yang telah dikonfigurasi
  ledcAttachPin(PWM_PIN1, 0);  // Pin PWM1 ke Channel 0
  ledcAttachPin(PWM_PIN2, 1);  // Pin PWM2 ke Channel 1
}

void setPWM(uint8_t pin, uint8_t dutyCycle) {
  uint8_t channel = (pin == PWM_PIN1) ? 0 : 1;  // Pilih channel berdasarkan pin
  uint32_t duty = (dutyCycle * 255) / 100;
  ledcWrite(channel, duty);
}