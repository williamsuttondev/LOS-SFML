#include "RenderLoop.h"

#define FPS 60

int main() {
    RenderLoop renderLoop(FPS);
    renderLoop.run();
    return 0;
}