// Pong

#include "bios.h"

const uint8_t ScreenWidth = 255;
const uint8_t ScreenHeight = 255;
const int8_t ScreenMaxX = 127;
const int8_t ScreenMinX = -128;
const int8_t ScreenMaxY = 127;
const int8_t ScreenMinY = -128;

struct VectorList {
    // Number of (y,x) vertices - 1
    int8_t count;
    // Array of (y,x) offsets to move beam
    int8_t vertices[4];
};

VectorList lines;

int main() {
    lines.count = 1;
    lines.vertices[0] = 10;
    lines.vertices[1] = 10;
    lines.vertices[2] = -10;
    lines.vertices[3] = -10;
    bios::Init();

    while (true) {
        bios::WaitFrame();

        bios::ZeroBeam();
        bios::Draw(&lines, 0, 0, bios::DefaultScale);
    }

    return 0;
}
