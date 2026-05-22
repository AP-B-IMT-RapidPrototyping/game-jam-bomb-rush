//
// Created by jorga on 22/05/2026.
//

#include "Map.h"

void Map::Draw() {
    DrawRectangle(position.x, position.y, 800, 50, GREEN);
}

void Map::Update() {
    if (IsKeyPressed(KEY_D)) { position.x--; }
    if (IsKeyPressed(KEY_A)) { position.x++; }
}
