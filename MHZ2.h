/* Keterangan
  a2 = pwm_high_start_ticks
  b2 = pwm_high_end_ticks
  c2 = pwm_high_val
  d2 = pwm_low_val
  CO2v2 = concentration
  f2 = flag
  g = pwm_high_val_ms
*/

#define pinCO22 12

// Konstanta untuk Moving Average
const int numSamples2 = 10;  // Jumlah sampel untuk rata-rata
double samples2[numSamples2]; // Buffer untuk data CO2
int currentIndex2 = 0;       // Indeks untuk menyimpan data terbaru

unsigned long a2 = 0, b2 = 0;
double c2 = 0, d2 = 0;
volatile uint8_t f2 = 0;
double CO2v2, mhz_outlet;

void interrupt_rising2();
void interrupt_falling2();

void interrupt_rising2() {
  a2 = micros();
  if (2 == f2) {
    f2 = 4;
    d2 = a2 - b2;
  } else {
    f2 = 1;
  }

  attachInterrupt(digitalPinToInterrupt(pinCO22), interrupt_falling2, FALLING);
}

void interrupt_falling2() {
  b2 = micros();
  if (1 == f2) {
    f2 = 2;
    c2 = b2 - a2;
  }
  attachInterrupt(digitalPinToInterrupt(pinCO22), interrupt_rising2, RISING);
}

void MHZ2_Setup() {
  pinMode(pinCO22, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinCO22), interrupt_rising2, RISING);
}

void MHZ2_Loop() {
  if (f2 == 4) {
    f2 = 1;
    double g2 = (c2 * 1000) / (d2 + c2);
    CO2v2 = (((g2 - 2) * 5) + 500);
    if (CO2v2 > 0) mhz_outlet = CO2v2;
  }
}