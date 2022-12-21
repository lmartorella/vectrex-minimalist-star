#include "bios.h"
#include "vectrex.h"

namespace bios {
    void SetScale(uint8_t scale) {
        VIA_t1_cnt_lo = scale;
    }
} // namespace bios
