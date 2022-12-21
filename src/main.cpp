#include "bios.h"
#include "vectrex.h"

struct VectorList {
    // Number of (y,x) vertices - 1
    int8_t count;
    // Array of (y,x) offsets to move beam
    int8_t vertices[16];
};

int main() {
    bios::Init();
    VectorList lines;
    lines.count = 7;

    while (true) {
        bios::WaitFrame();
        bios::ZeroBeam();
        bios::SetScale(bios::DefaultScale);
        Moveto_d(-25, -50);
        {
            int8_t deltaX1 = 75;   // 50
            int8_t deltaY1 = 75;   // 50
            int8_t deltaX2 = -100; // -50
            int8_t deltaY2 = 0;    // 50
            {
                lines.vertices[0] = deltaY1;
                lines.vertices[1] = deltaX1;
                lines.vertices[2] = deltaY2;
                lines.vertices[3] = deltaX2;
            }
        }
        {
            int8_t deltaX1 = 75;  // 50
            int8_t deltaY1 = -75; // -50
            int8_t deltaX2 = 0;   // 50
            int8_t deltaY2 = 100; // 50
            {
                lines.vertices[4] = deltaY1;
                lines.vertices[5] = deltaX1;
                lines.vertices[6] = deltaY2;
                lines.vertices[7] = deltaX2;
            }
        }
        {
            int8_t deltaX1 = -75; // -50
            int8_t deltaY1 = -75; // -25
            int8_t deltaX2 = 100; // 50
            int8_t deltaY2 = 0;   // -25
            {
                lines.vertices[8] = deltaY1;
                lines.vertices[9] = deltaX1;
                lines.vertices[10] = deltaY2;
                lines.vertices[11] = deltaX2;
            }
        }
        {
            int8_t deltaX1 = -75;  // -25
            int8_t deltaY1 = 75;   // 50
            int8_t deltaX2 = 0;    // -25
            int8_t deltaY2 = -100; // -50
            {
                lines.vertices[12] = deltaY1;
                lines.vertices[13] = deltaX1;
                lines.vertices[14] = deltaY2;
                lines.vertices[15] = deltaX2;
            }
        }

        Draw_VLc(&lines);
    }

    return 0;
}
