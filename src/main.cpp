#include "RenderLoop.h"
#include "TileSheetManager.h"

#define FPS 12

int main() {
    RenderLoop renderLoop(FPS);
    renderLoop.run();
    return 0;
}