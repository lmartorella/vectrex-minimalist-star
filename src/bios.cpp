#include "bios.h"
#include "vectrex.h"

namespace bios {
    void Init() {
        SetBeamIntensity(DefaultIntensity);
        SetScale(DefaultScale);
    }

    void WaitFrame() {
        Wait_Recal();

        // Need to set beam intensity after Wait_Recal.
        // In fact, Joy_Digital also seems to reset intensity to 0.
        // We may need to call this each time we draw.
        SetBeamIntensity(DefaultIntensity);
    }

    void ZeroBeam() {
        Reset0Ref();
    }

    void SetBeamIntensity(int8_t intensity) {
        Intensity_a(intensity);
    }

    void SetScale(uint8_t scale) {
        VIA_t1_cnt_lo = scale;
    }

    void Draw(const void* vectorList, int8_t relx, int8_t rely, uint8_t scale) {
        SetScale(scale);
        Moveto_d(relx, rely);
        Draw_VLc(vectorList);
    }
} // namespace bios
