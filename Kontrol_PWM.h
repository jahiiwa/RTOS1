#ifndef PWM_H
#define PWM_H

#include <Arduino.h>

// Define PWM pins for ESP32
#define PWM_PIN1 2
#define PWM_PIN2 3

void setupPWM();
void setPWM(uint8_t pin, uint8_t dutyCycle);

#endif
