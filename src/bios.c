#include "bios.h"
#include "vectrex.h"

void SetScale(uint8_t scale) {
    VIA_t1_cnt_lo = scale;
}
