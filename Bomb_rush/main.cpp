#include <iostream>

#include "Map.h"
#include "raylib.h"

//file(COPY "Assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
//voor cmakelists als we assets nodig gaan hebben

int main() {
    InitWindow(800,600,"Bomb Rush");
    SetTargetFPS(60);
    Map *map = new Map();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        map->Draw();
        map->Update();

        EndDrawing();
    }
    return 0;
}

