#include <iostream>

#include "Bullet.h"
#include "Enemy.h"
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
    Timer *timer = new Timer();
    Player *player = new Player();
    Enemy *enemy = new Enemy();


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        map->Draw();
        player->Draw();
        player->Update();
        map->Update();
        timer->DrawTimer();
        enemy->Draw();
        EndDrawing();
    }
    return 0;
}