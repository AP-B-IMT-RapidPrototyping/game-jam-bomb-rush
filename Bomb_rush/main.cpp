#include <iostream>

#include "Map.h"
#include "Player.h"
#include "raylib.h"
#include "Timer.h"

//file(COPY "Assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
//voor cmakelists als we assets nodig gaan hebben

int main() {
    InitWindow(800,600,"Bomb Rush");
    SetTargetFPS(60);
    Map *map = new Map();
    Timer timer = Timer();
    Player *player = new Player();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        map->Draw();
        player->Draw();
        map->Update();
        DrawText(TextFormat("Elapsed Time: %02.02f s", GetTime()), 10, 10, 30, BLACK);

        EndDrawing();
    }
    return 0;
}