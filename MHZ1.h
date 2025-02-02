/* Keterangan
  a1 = pwm_high_start_ticks
  b1 = pwm_high_end_ticks
  c1 = pwm_high_val
  d1 = pwm_low_val
  CO2v1 = concentration
  f1 = flag
  g = pwm_high_val_ms
*/

#define pinCO21 14

unsigned long a1 = 0, b1 = 0;
double c1 = 0, d1 = 0;
volatile uint8_t f1 = 0;
double CO2v1, mhz_inlet;

void interrupt_rising1();
void interrupt_falling1();

void interrupt_rising1() {
  a1 = micros();
  if (2 == f1) {
    f1 = 4;
    d1 = a1 - b1;
  } else {
    f1 = 1;
  }

  attachInterrupt(digitalPinToInterrupt(pinCO21), interrupt_falling1, FALLING);
}

void interrupt_falling1() {
  b1 = micros();
  if (1 == f1) {
    f1 = 2;
    c1 = b1 - a1;
  }
  attachInterrupt(digitalPinToInterrupt(pinCO21), interrupt_rising1, RISING);
}

void MHZ1_Setup() {
  pinMode(pinCO21, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinCO21), interrupt_rising1, RISING);
}

void MHZ1_Loop() {
  if (f1 == 4) {
    f1 = 1;
    double g1 = (c1 * 1000) / (d1 + c1);
    CO2v1 = ((g1 - 2) * 5);
    if (CO2v1 > 0){
      mhz_inlet = CO2v1;
    }
  }
}