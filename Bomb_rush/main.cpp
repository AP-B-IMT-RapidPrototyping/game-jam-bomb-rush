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
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"Bomb Rush");
    SetTargetFPS(60);

    Player player = Player();
    Map envItems[] = {
    {{-800, 0, 2400, 600}, 0, BROWN},
    {{-800, 550, 2400, 50}, 1, GREEN},
    {{0, 400, 100, 30}, 1, GREEN},
    {{100, 500, 240, 50}, 1, GREEN}
    };

    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    Camera2D camera = { 0 };
    camera.target = player.position;
    camera.offset = {screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Timer *timer = new Timer();
    Enemy *enemy = new Enemy();
    Bullet *bullet = new Bullet(player.position);


    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        player.Update(envItems, envItemsLength, deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);

        for (int i = 0; i < envItemsLength; i++) {
            DrawRectangleRec(envItems[i].rect, envItems[i].color);
        }

        player.playerRect = {player.position.x - 15, player.position.y -50, 30, 50};
        DrawRectangleRec(player.playerRect, BLUE);
        DrawCircleV(player.position, 5.0f, GOLD);

        EndMode2D();
        timer->DrawTimerBackwards();
        timer->DrawTimer();
        enemy->Draw();
        enemy->Update(*bullet);
        DrawRectangleRec(bullet->GetBody(),BLACK);
        bullet->Draw();
        bullet->Update();
        EndDrawing();
    }
    return 0;
}