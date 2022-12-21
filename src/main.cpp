#include "bios.h"
#include "vectrex.h"

struct VectorList {
    // Number of (y,x) vertices - 1
    int8_t count;
    // Array of (y,x) offsets to move beam
    struct {
        int8_t deltaY;
        int8_t deltaX;
    } lines[8];
};

int main() {
    VectorList lines;
    lines.count = 7;
    Intensity_a(127);

    while (true) {
        Wait_Recal();
        Intensity_a(127);

        Reset0Ref(); // zero beam

        bios::SetScale(bios::DefaultScale);
        Moveto_d(-25, -50);
        {
            int8_t deltaX1 = 75;   // 50
            int8_t deltaY1 = 75;   // 50
            int8_t deltaX2 = -100; // -50
            int8_t deltaY2 = 0;    // 50
            {
                lines.lines[0].deltaX = deltaX1;
                lines.lines[0].deltaY = deltaY1;
                lines.lines[1].deltaX = deltaX2;
                lines.lines[1].deltaY = deltaY2;
            }
        }
        {
            int8_t deltaX1 = 75;  // 50
            int8_t deltaY1 = -75; // -50
            int8_t deltaX2 = 0;   // 50
            int8_t deltaY2 = 100; // 50
            {
                lines.lines[2].deltaX = deltaX1;
                lines.lines[2].deltaY = deltaY1;
                lines.lines[3].deltaX = deltaX2;
                lines.lines[3].deltaY = deltaY2;
            }
        }
        {
            int8_t deltaX1 = -75; // -50
            int8_t deltaY1 = -75; // -25
            int8_t deltaX2 = 100; // 50
            int8_t deltaY2 = 0;   // -25
            {
                lines.lines[4].deltaX = deltaX1;
                lines.lines[4].deltaY = deltaY1;
                lines.lines[5].deltaX = deltaX2;
                lines.lines[5].deltaY = deltaY2;
            }
        }
        {
            int8_t deltaX1 = -75;  // -25
            int8_t deltaY1 = 75;   // 50
            int8_t deltaX2 = 0;    // -25
            int8_t deltaY2 = -100; // -50
            {
                lines.lines[6].deltaX = deltaX1;
                lines.lines[6].deltaY = deltaY1;
                lines.lines[7].deltaX = deltaX2;
                lines.lines[7].deltaY = deltaY2;
            }
        }

        Draw_VLc(&lines);
    }

    return 0;
}
