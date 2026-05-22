#include <cmath>
#include <iostream>

#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "raylib.h"
#include "Timer.h"

//file(COPY "Assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
//voor cmakelists als we assets nodig gaan hebben

void UpdateCameraMovement(Camera2D *camera, Player *player, Map *envItems, std::vector<Enemy*>enemies, int envItemsLength, float delta, int width, int height) {
    camera->target = player->position;
    camera->offset = (Vector2){ width/2.0f, height/2.0f };
    float minX = 1000, minY = 1000, maxX=-1000, maxY=-1000;

    for (int i = 0; i < envItemsLength; i++) {
        Map *ei = envItems + i;
        minX = fminf(ei->rect.x, minX);
        maxX = fmaxf(ei->rect.x + ei->rect.width, maxX);
        minY = fminf(ei->rect.y, minY);
        maxY = fmaxf(ei->rect.y + ei->rect.height, maxY);
    }

    Vector2 max = GetWorldToScreen2D({maxX, maxY}, *camera);
    Vector2 min = GetWorldToScreen2D({minX, minY}, *camera);

    if (max.x < width) camera->offset.x = width - (max.x - (float)width/2);
    if (max.y < width) camera->offset.y = height - (max.y - (float)height/2);
    if (min.x > 0) camera->offset.x = (float)width/2 - min.x;
    if (max.y > 0) camera->offset.y = (float)height/2 - min.y;
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"Bomb Rush");
    SetTargetFPS(60);

    Player player = Player();
    Map envItems[] = {
        {{-800, 0, 2400, 600}, 0, LIGHTGRAY},
    {{-800, 550, 2400, 50}, 1, GREEN},
    {{0, 400, 100, 30}, 1, GREEN},
    {{200, 450, 240, 30}, 1, GREEN},
    {{450, 425, 175, 30}, 1, GREEN},
    {{650, 380, 265, 30}, 1, GREEN},
    {{1000, 400, 215, 30}, 1, GREEN}
    };

    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    Camera2D camera = { 0 };
    camera.target = player.position;
    camera.offset = {screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Timer *timer = new Timer();

    std::vector<Bullet*> bullets;
    std::vector<Enemy*> enemies;


    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        player.Update(envItems, envItemsLength, deltaTime);
        UpdateCameraMovement(&camera, &player, envItems, enemies, envItemsLength, deltaTime, screenWidth, screenHeight);

        if (IsKeyPressed(KEY_E)) {
            bullets.push_back(new Bullet(player.position, player.lookingLeft));
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i]->Update();
        }

        enemies.push_back(new Enemy({30,360}));
        enemies.push_back(new Enemy({250,410}));
        enemies.push_back(new Enemy({500,385}));
        enemies.push_back(new Enemy({700,340}));
        enemies.push_back(new Enemy({1100,360}));

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);

        for (int i = 0; i < envItemsLength; i++) {
            DrawRectangleRec(envItems[i].rect, envItems[i].color);
        }
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->Draw();
        }

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i]->Draw();
        }


        player.playerRect = {player.position.x - 15, player.position.y -50, 30, 50};
        DrawRectangleRec(player.playerRect, BLUE);
        DrawCircleV(player.position, 5.0f, GOLD);

        EndMode2D();
        timer->DrawTimer();
        EndDrawing();
    }
    return 0;
}