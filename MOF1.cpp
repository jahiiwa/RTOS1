#include "MOF1.h"

int a0;
float mof_inlet;

void MOF1_Loop() {
    a0 = ads.readADC_SingleEnded(0);
    mof_inlet = (a0 * pga_range) / 32767.0;
}
