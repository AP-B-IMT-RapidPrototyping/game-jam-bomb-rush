//
// Created by jorga on 22/05/2026.
//

#include "Map.h"

void Map::Draw() {
    DrawRectangle(position.x,0,2400,600,BROWN);
    DrawRectangle(position.x, 550, 2400, 50, GREEN);
    DrawRectangle(position.x + 250, 400, 120, 35, GREEN);
    DrawRectangle(position.x + 600, 500, 550, 50, GREEN);
    DrawRectangle(position.x + 700, 450, 200, 50, GREEN);
}

void Map::Update() {
    if (IsKeyDown(KEY_D) && position.x >= -2000) { this->position.x -= 5; }
    if (IsKeyDown(KEY_A) && position.x <= 400) { this->position.x += 5; }
}
