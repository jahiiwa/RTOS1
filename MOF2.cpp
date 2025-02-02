#include "MOF2.h"

int a3;
float mof_outlet;

void MOF2_Loop() {
    a3 = ads.readADC_SingleEnded(3);
    mof_outlet = (a3 * pga_range) / 32767.0;
}
