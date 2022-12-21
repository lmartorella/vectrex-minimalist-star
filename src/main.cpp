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

        lines.lines[0].deltaX = lines.lines[2].deltaX = 75;
        lines.lines[4].deltaX = lines.lines[6].deltaX = -75;

        lines.lines[0].deltaY = lines.lines[6].deltaY = 75;
        lines.lines[2].deltaY = lines.lines[4].deltaY = -75;

        lines.lines[1].deltaX = -100;
        lines.lines[5].deltaX = 100;
        lines.lines[3].deltaX = lines.lines[7].deltaX = 0;

        lines.lines[1].deltaY = lines.lines[5].deltaY = 0;
        lines.lines[3].deltaY = 100;
        lines.lines[7].deltaY = -100;

        Draw_VLc(&lines);
    }

    return 0;
}
