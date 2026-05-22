#include <iostream>
#include "raylib.h"

//file(COPY "Assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
//voor cmakelists als we assets nodig gaan hebben

int main() {
    InitWindow(800,600,"Bomb Rush");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();



        EndDrawing();
    }
    return 0;
}

